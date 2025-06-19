/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:45:05 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/06 23:53:26 by takitaga         ###   ########.fr       */
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
	w->philos = NULL;
	w->forks = NULL;
	w->forks_mutex = NULL;
	result.error = create_success();
	result.error = parse_args_and_validate(w, argc, argv);
	if (result.error.is_error)
		return (result);
	w->philos = ft_calloc(w->num_of_philos, sizeof(t_philo));
	if (w->philos == NULL)
	{
		result.error = create_error(ERR_MEMORY);
		return (result);
	}
	result.error = init_resources(w);
	return (result);
}

void	cleanup_waiter(t_waiter *w)
{
	int	i;

	i = 0;
	while (i < w->num_of_forks)
	{
		pthread_mutex_destroy(&w->forks_mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&w->print_mutex);
	pthread_mutex_destroy(&w->stop_mutex);
	ft_free(w->philos);
	ft_free(w->forks);
	ft_free(w->forks_mutex);
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

	error = init_forks(w);
	if (error.is_error)
		return (error);
	if (pthread_mutex_init(&w->print_mutex, NULL) != 0)
		return (create_error(ERR_MUTEX_INIT));
	if (pthread_mutex_init(&w->stop_mutex, NULL) != 0)
		return (create_error(ERR_MUTEX_INIT));
	w->should_stop = false;
	return (error);
}
