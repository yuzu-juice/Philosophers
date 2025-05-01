/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:20:14 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 01:26:58 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void						*philo_thread(void *arg);
static t_pthread_t_ptr_result	create_threads(t_waiter *waiter);

t_error	philo(t_waiter waiter)
{
	t_pthread_t_ptr_result	result;

	result = create_threads(&waiter);
	if (result.error.is_error)
		return (result.error);
	usleep(1000);
	return (create_success());
}

static void	*philo_thread(void *waiter)
{
	(void)waiter;
	printf("Philosopher thread is running...\n");
	return (NULL);
}

static t_pthread_t_ptr_result	create_threads(t_waiter *waiter)
{
	t_pthread_t_ptr_result	result;
	int						i;

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
		if (pthread_create(&result.tid[i], NULL, philo_thread, waiter) != 0)
		{
			result.error = create_error(ERR_THREAD_CREATE);
			return (result);
		}
		i++;
	}
	return (result);
}
