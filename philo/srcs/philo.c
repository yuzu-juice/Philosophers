/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:20:14 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 02:54:45 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void						*philo_thread(void *arg);
static t_pthread_t_ptr_result	create_threads(t_waiter *waiter);

t_error	philo(t_waiter waiter)
{
	t_pthread_t_ptr_result	result;
	int						i;

	result = create_threads(&waiter);
	if (result.error.is_error)
		return (result.error);
	i = 0;
	while (i < waiter.num_of_philos)
	{
		pthread_join(result.tid[i], NULL);
		i++;
	}
	return (create_success());
}

static void	*philo_thread(void *arg)
{
	t_info		*info;
	t_waiter	*waiter;

	info = (t_info *)arg;
	waiter = info->waiter;
	pthread_mutex_lock(&(waiter->forks[0]));
	usleep(0.5 * 1000 * 1000);
	printf("%d has taken a fork.\n", info->philo_id);
	pthread_mutex_unlock(&(waiter->forks[0]));
	free(info);
	return (NULL);
}

static t_pthread_t_ptr_result	create_threads(t_waiter *waiter)
{
	t_pthread_t_ptr_result	result;
	int						i;
	t_info					*info;

	result.error.is_error = false;
	result.error.message = NULL;
	i = 0;
	result.tid = ft_calloc(waiter->num_of_philos, sizeof(pthread_t));
	if (result.tid == NULL)
	{
		result.error = create_error(ERR_MEMORY);
		return (result);
	}
	while (i < waiter->num_of_philos)
	{
		info = ft_calloc(1, sizeof(t_info));
		if (info == NULL)
		{
			result.error = create_error(ERR_MEMORY);
			return (result);
		}
		info->waiter = waiter;
		info->philo_id = i;
		if (pthread_create(&result.tid[i], NULL, philo_thread, info) != 0)
		{
			result.error = create_error(ERR_THREAD_CREATE);
			return (result);
		}
		i++;
	}
	return (result);
}
