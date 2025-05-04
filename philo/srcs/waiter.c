/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:45:05 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/05 01:50:25 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_waiter_result	init_waiter(int argc, char **argv)
{
	t_waiter_result	result;
	t_waiter		*w;

	w = &result.w;
	result.error = create_success();
	w->start_time = timestamp();
	w->num_of_philos = ft_atouint(argv[1]);
	w->num_of_forks = w->num_of_philos;
	w->time_to_die = ft_atouint(argv[2]);
	w->time_to_eat = ft_atouint(argv[3]);
	w->time_to_sleep = ft_atouint(argv[4]);
	if (argc == 6)
		w->num_of_times_each_philo_must_eat = ft_atouint(argv[5]);
	else
		w->num_of_times_each_philo_must_eat = INT_MAX;
	if (w->num_of_philos <= 0 || w->num_of_philos >= 1000 || w->time_to_die <= 0
		|| w->time_to_eat <= 0 || w->time_to_sleep <= 0
		|| (argc == 6 && w->num_of_times_each_philo_must_eat <= 0))
		result.error = create_error(ERR_INVALID_ARGS);
	if (result.error.is_error)
		return (result);
	result.error = init_print_mutex(w);
	if (result.error.is_error)
		return (result);
	result.error = init_forks_mutex(w);
	if (result.error.is_error)
		return (result);
	result.error = init_eat_count(w);
	if (result.error.is_error)
		return (result);
	result.error = init_is_dead(w);
	if (result.error.is_error)
		return (result);
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
	free(w->eat_count);
	free(w->is_dead);
	free(w->forks_mutex);
	free(w->print_mutex);
	free(w->eat_count_mutex);
	free(w->is_dead_mutex);
	w->eat_count = NULL;
	w->is_dead = NULL;
	w->forks_mutex = NULL;
	w->print_mutex = NULL;
	w->eat_count_mutex = NULL;
	w->is_dead_mutex = NULL;
}
