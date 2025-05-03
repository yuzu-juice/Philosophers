/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:20:14 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/04 00:35:24 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_pthread_ptr_result	create_threads(t_waiter *w);
static t_pthread_ptr_result	create_pthread_error(pthread_t *tid, char *msg);
static t_info_result		create_info(t_waiter *w, int philo_id);

t_error	philo(t_waiter w)
{
	t_pthread_ptr_result	result;
	pthread_t				watchdog_th;
	int						i;

	if (w.num_of_philos == 1)
		return (create_success());
	if (pthread_create(&watchdog_th, NULL, watchdog, &w) != 0)
		return (create_error(ERR_THREAD_CREATE));
	result = create_threads(&w);
	if (result.error.is_error)
		return (result.error);
	i = 0;
	while (i < w.num_of_philos)
	{
		pthread_join(result.tid[i], NULL);
		i++;
	}
	pthread_join(watchdog_th, NULL);
	free(result.tid);
	return (create_success());
}

static t_pthread_ptr_result	create_threads(t_waiter *w)
{
	t_pthread_ptr_result	result;
	t_info_result			info_result;
	t_info					*info;
	int						i;

	result.error = create_success();
	i = 0;
	result.tid = ft_calloc(w->num_of_philos, sizeof(pthread_t));
	if (result.tid == NULL)
		return (create_pthread_error(result.tid, ERR_MEMORY));
	while (i < w->num_of_philos)
	{
		info_result = create_info(w, i);
		if (info_result.error.is_error)
			return (create_pthread_error(result.tid, info_result.error.msg));
		info = info_result.info;
		if (pthread_create(&result.tid[i], NULL, philo_thread, info) != 0)
		{
			free(info);
			return (create_pthread_error(result.tid, ERR_THREAD_CREATE));
		}
		i++;
	}
	return (result);
}

static t_info_result	create_info(t_waiter *w, int philo_id)
{
	t_info_result	result;

	result.error = create_success();
	result.info = ft_calloc(1, sizeof(t_info));
	if (result.info == NULL)
	{
		result.error = create_error(ERR_MEMORY);
		return (result);
	}
	result.info->w = w;
	result.info->philo_id = philo_id;
	result.info->l_fork_id = philo_id;
	result.info->r_fork_id = (philo_id + 1) % w->num_of_philos;
	result.info->w->eat_count[philo_id] = 0;
	result.info->last_meal_time = timestamp();
	return (result);
}

static t_pthread_ptr_result	create_pthread_error(pthread_t *tid, char *msg)
{
	t_pthread_ptr_result	result;

	result.tid = tid;
	result.error.is_error = true;
	result.error.msg = msg;
	if (tid != NULL)
		free(tid);
	return (result);
}
