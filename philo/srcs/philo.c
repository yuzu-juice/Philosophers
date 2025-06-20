/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:20:14 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 07:03:33 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_philo_result		init_philo(t_table *t, int philo_id);
static t_error				allocate_philo_resources(t_table *t,
								t_pthread_ptr_result *result);
static t_error				create_and_launch_philo(t_table *t,
								t_pthread_ptr_result *result, int i);
static t_pthread_ptr_result	create_philo_threads(t_table *t);

t_error	philo(t_table t)
{
	t_pthread_ptr_result	result;
	pthread_t				watchdog_th;
	int						i;

	if (t.num_of_philos == 1)
		return (solo_philo(&t));
	result = create_philo_threads(&t);
	if (result.error.is_error)
		return (free_t_pthread_ptr(&result), result.error);
	i = -1;
	if (pthread_create(&watchdog_th, NULL, watchdog, &t) != 0)
	{
		set_stop_flag(&t);
		while (++i < t.num_of_philos)
			pthread_join(result.tid[i], NULL);
		free_t_pthread_ptr(&result);
		return (create_error(ERR_THREAD_CREATE));
	}
	while (++i < t.num_of_philos)
		pthread_join(result.tid[i], NULL);
	pthread_join(watchdog_th, NULL);
	free_t_pthread_ptr(&result);
	return (create_success());
}

static t_philo_result	init_philo(t_table *t, int philo_id)
{
	t_philo_result	result;

	result.philo = ft_calloc(1, sizeof(t_philo));
	if (result.philo == NULL)
	{
		result.error = create_error(ERR_MEMORY);
		return (result);
	}
	if (pthread_mutex_init(&result.philo->philo_mutex, NULL) != 0)
	{
		ft_free(result.philo);
		result.error = create_error(ERR_MUTEX_INIT);
		return (result);
	}
	result.error = create_success();
	result.philo->philo_id = philo_id;
	result.philo->l_fork_id = philo_id;
	result.philo->r_fork_id = (philo_id + 1) % t->num_of_philos;
	result.philo->eat_count = 0;
	result.philo->last_meal_time = t->start_time;
	return (result);
}

static t_error	allocate_philo_resources(t_table *t,
										t_pthread_ptr_result *result)
{
	result->tid = ft_calloc(t->num_of_philos, sizeof(pthread_t));
	if (result->tid == NULL)
		return (create_error(ERR_MEMORY));
	result->args = ft_calloc(t->num_of_philos, sizeof(t_thread_arg));
	if (result->args == NULL)
	{
		ft_free(result->tid);
		result->tid = NULL;
		return (create_error(ERR_MEMORY));
	}
	return (create_success());
}

static t_error	create_and_launch_philo(t_table *t,
										t_pthread_ptr_result *result, int i)
{
	t_philo_result	philo_result;

	philo_result = init_philo(t, i);
	if (philo_result.error.is_error)
		return (philo_result.error);
	t->philos[i] = *philo_result.philo;
	result->args[i].t = t;
	result->args[i].philo_id = i;
	if (pthread_create(&result->tid[i], NULL, philo_thread,
			&result->args[i]) != 0)
	{
		ft_free(philo_result.philo);
		return (create_error(ERR_THREAD_CREATE));
	}
	ft_free(philo_result.philo);
	return (create_success());
}

static t_pthread_ptr_result	create_philo_threads(t_table *t)
{
	t_pthread_ptr_result	result;
	t_error					status;
	int						i;

	result.error = create_success();
	result.tid = NULL;
	result.args = NULL;
	status = allocate_philo_resources(t, &result);
	if (status.is_error)
	{
		result.error = status;
		return (result);
	}
	i = 0;
	while (i < t->num_of_philos)
	{
		status = create_and_launch_philo(t, &result, i);
		if (status.is_error)
		{
			result.error = status;
			return (result);
		}
		i++;
	}
	return (result);
}
