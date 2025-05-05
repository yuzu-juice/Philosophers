/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:45:05 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/05 15:37:01 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_error	parse_args_and_validate(t_waiter *w, int argc, char **argv);
static t_error	init_resources(t_waiter *w);

t_waiter_result	init_waiter(int argc, char **argv)
{
	t_waiter_result	result;
	t_waiter		*w;

	w = &result.w;
	result.error = create_success();
	result.error = parse_args_and_validate(w, argc, argv);
	if (!result.error.is_error)
		result.error = init_resources(w);
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
	pthread_mutex_destroy(w->print_mutex);
	pthread_mutex_destroy(w->eat_count_mutex);
	pthread_mutex_destroy(w->is_dead_mutex);
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

static t_error	parse_args_and_validate(t_waiter *w, int argc, char **argv)
{
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
		return (create_error(ERR_INVALID_ARGS));
	return (create_success());
}

static t_error	init_resources(t_waiter *w)
{
	t_error	error;

	error = init_print_mutex(w);
	if (error.is_error)
		return (error);
	error = init_forks_mutex(w);
	if (error.is_error)
		return (error);
	error = init_eat_count(w);
	if (error.is_error)
		return (error);
	error = init_is_dead(w);
	return (error);
}
