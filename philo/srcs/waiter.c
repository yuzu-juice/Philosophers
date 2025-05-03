/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:45:05 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/03 20:24:46 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_waiter_result	init_waiter(int argc, char **argv)
{
	t_waiter_result	result;

	result.error = create_success();
	result.w.start_time = timestamp();
	result.w.num_of_philos = ft_atouint(argv[1]);
	result.w.num_of_forks = result.w.num_of_philos;
	result.w.time_to_die = ft_atouint(argv[2]);
	result.w.time_to_eat = ft_atouint(argv[3]);
	result.w.time_to_sleep = ft_atouint(argv[4]);
	if (argc == 6)
		result.w.num_of_times_each_philo_must_eat = ft_atouint(argv[5]);
	else
		result.w.num_of_times_each_philo_must_eat = -1;
	if (result.w.num_of_philos <= 0 || result.w.time_to_die <= 0
		|| result.w.time_to_eat <= 0 || result.w.time_to_sleep <= 0
		|| (argc == 6 && result.w.num_of_times_each_philo_must_eat <= 0))
		result.error = create_error(ERR_INVALID_ARGS);
	if (result.error.is_error)
		return (result);
	result.error = init_print_mutex(&result.w);
	result.error = init_forks_mutex(&result.w);
	result.error = init_eat_count(&result.w);
	result.error = init_is_dead(&result.w);
	return (result);
}

void	cleanup_waiter(t_waiter *w)
{
	int	i;

	i = 0;
	while (i < w->num_of_forks)
	{
		pthread_mutex_destroy(&(w->forks_mutex[i]));
		i++;
	}
	free(w->forks_mutex);
	w->forks_mutex = NULL;
}
