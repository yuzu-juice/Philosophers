/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:20:14 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 03:58:36 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void					*philo_thread(void *arg);
static t_pthread_ptr_result	create_threads(t_waiter *waiter);
static t_pthread_ptr_result	create_pthread_error(pthread_t *tid, char *msg);
static t_info_result		create_info(t_waiter *waiter, int philo_id);

t_error	philo(t_waiter waiter)
{
	t_pthread_ptr_result	result;
	int						i;

	if (waiter.num_of_philos == 1)
		return (create_success());
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
	int			fork_id_smaller;
	int			fork_id_bigger;

	info = (t_info *)arg;
	waiter = info->waiter;
	if (info->left_fork_id < info->right_fork_id)
	{
		fork_id_smaller = info->left_fork_id;
		fork_id_bigger = info->right_fork_id;
	}
	else
	{
		fork_id_smaller = info->right_fork_id;
		fork_id_bigger = info->left_fork_id;
	}
	pthread_mutex_lock(&(waiter->forks[fork_id_smaller]));
	pthread_mutex_lock(&(waiter->forks[fork_id_bigger]));
	usleep(waiter->time_to_eat * 1000);
	printf("%d has taken a fork.\n", info->philo_id);
	pthread_mutex_unlock(&(waiter->forks[fork_id_bigger]));
	pthread_mutex_unlock(&(waiter->forks[fork_id_smaller]));
	free(info);
	return (NULL);
}

static t_pthread_ptr_result	create_threads(t_waiter *waiter)
{
	t_pthread_ptr_result	result;
	t_info_result			info_result;
	t_info					*info;
	int						i;

	result.error = create_success();
	i = 0;
	result.tid = ft_calloc(waiter->num_of_philos, sizeof(pthread_t));
	if (result.tid == NULL)
		return (create_pthread_error(result.tid, ERR_MEMORY));
	while (i < waiter->num_of_philos)
	{
		info_result = create_info(waiter, i);
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

static t_info_result	create_info(t_waiter *waiter, int philo_id)
{
	t_info_result	result;

	result.error = create_success();
	result.info = ft_calloc(1, sizeof(t_info));
	if (result.info == NULL)
	{
		result.error = create_error(ERR_MEMORY);
		return (result);
	}
	result.info->waiter = waiter;
	result.info->philo_id = philo_id;
	result.info->left_fork_id = philo_id;
	result.info->right_fork_id = (philo_id + 1) % waiter->num_of_philos;
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
