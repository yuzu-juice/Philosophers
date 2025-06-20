/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:20:14 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 06:38:24 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_philo_result		init_philo(t_waiter *w, int philo_id);
static t_error				allocate_philo_resources(t_waiter *w,
								t_pthread_ptr_result *result);
static t_error				create_and_launch_philo(t_waiter *w,
								t_pthread_ptr_result *result, int i);
static t_pthread_ptr_result	create_philo_threads(t_waiter *w);

t_error	philo(t_waiter w)
{
	t_pthread_ptr_result	result;
	pthread_t				watchdog_th;
	int						i;

	if (w.num_of_philos == 1)
		return (print_status(&w, 0, DIED));
	result = create_philo_threads(&w);
	if (result.error.is_error)
		return (free_t_pthread_ptr(&result), result.error);
	i = -1;
	if (pthread_create(&watchdog_th, NULL, watchdog, &w) != 0)
	{
		set_stop_flag(&w);
		while (++i < w.num_of_philos)
			pthread_join(result.tid[i], NULL);
		free_t_pthread_ptr(&result);
		return (create_error(ERR_THREAD_CREATE));
	}
	while (++i < w.num_of_philos)
		pthread_join(result.tid[i], NULL);
	pthread_join(watchdog_th, NULL);
	free_t_pthread_ptr(&result);
	return (create_success());
}

static t_philo_result	init_philo(t_waiter *w, int philo_id)
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
	result.philo->r_fork_id = (philo_id + 1) % w->num_of_philos;
	result.philo->eat_count = 0;
	result.philo->last_meal_time = w->start_time;
	return (result);
}

static t_error	allocate_philo_resources(t_waiter *w,
										t_pthread_ptr_result *result)
{
	result->tid = ft_calloc(w->num_of_philos, sizeof(pthread_t));
	if (result->tid == NULL)
		return (create_error(ERR_MEMORY));
	result->args = ft_calloc(w->num_of_philos, sizeof(t_thread_arg));
	if (result->args == NULL)
	{
		ft_free(result->tid);
		result->tid = NULL;
		return (create_error(ERR_MEMORY));
	}
	return (create_success());
}

static t_error	create_and_launch_philo(t_waiter *w,
										t_pthread_ptr_result *result, int i)
{
	t_philo_result	philo_result;

	philo_result = init_philo(w, i);
	if (philo_result.error.is_error)
		return (philo_result.error);
	w->philos[i] = *philo_result.philo;
	result->args[i].w = w;
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

static t_pthread_ptr_result	create_philo_threads(t_waiter *w)
{
	t_pthread_ptr_result	result;
	t_error					status;
	int						i;

	result.error = create_success();
	result.tid = NULL;
	result.args = NULL;
	status = allocate_philo_resources(w, &result);
	if (status.is_error)
	{
		result.error = status;
		return (result);
	}
	i = 0;
	while (i < w->num_of_philos)
	{
		status = create_and_launch_philo(w, &result, i);
		if (status.is_error)
		{
			result.error = status;
			return (result);
		}
		i++;
	}
	return (result);
}
