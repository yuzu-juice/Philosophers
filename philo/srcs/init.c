/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:45:05 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 02:05:01 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_error	init_forks(t_waiter *waiter);

t_waiter_result	init_waiter(int argc, char **argv)
{
	t_waiter_result	result;

	result.error.is_error = false;
	result.error.message = NULL;
	result.waiter.num_of_philos = ft_atouint(argv[1]);
	result.waiter.num_of_forks = result.waiter.num_of_philos;
	result.waiter.time_to_die = ft_atouint(argv[2]);
	result.waiter.time_to_eat = ft_atouint(argv[3]);
	result.waiter.time_to_sleep = ft_atouint(argv[4]);
	if (argc == 6)
		result.waiter.num_of_times_each_philo_must_eat = ft_atouint(argv[5]);
	else
		result.waiter.num_of_times_each_philo_must_eat = -1;
	if (result.waiter.num_of_philos <= 0 || result.waiter.time_to_die <= 0
		|| result.waiter.time_to_eat <= 0 || result.waiter.time_to_sleep <= 0
		|| (argc == 6 && result.waiter.num_of_times_each_philo_must_eat <= 0))
		result.error = create_error(ERR_INVALID_ARGS);
	if (result.error.is_error)
		return (result);
	result.error = init_forks(&result.waiter);
	if (result.error.is_error)
		return (result);
	return (result);
}

static t_error	init_forks(t_waiter *waiter)
{
	waiter->forks = ft_calloc(waiter->num_of_forks, sizeof(pthread_mutex_t));
	if (waiter->forks == NULL)
		return (create_error(ERR_MEMORY));
	return (create_success());
}
