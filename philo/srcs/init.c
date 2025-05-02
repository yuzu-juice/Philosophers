/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:45:05 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 17:15:15 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_error	init_forks_mutex(t_waiter *w);
static t_error	init_print_mutex(t_waiter *w);
static t_error	init_eat_count(t_waiter *w);

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

static t_error	init_forks_mutex(t_waiter *w)
{
	int	i;

	w->forks_mutex = ft_calloc(w->num_of_forks, sizeof(pthread_mutex_t));
	if (w->forks_mutex == NULL)
		return (create_error(ERR_MEMORY));
	i = 0;
	while (i < w->num_of_forks)
	{
		if (pthread_mutex_init(&(w->forks_mutex[i]), NULL) != 0)
		{
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&(w->forks_mutex[i]));
			}
			free(w->forks_mutex);
			return (create_error(ERR_MUTEX_INIT));
		}
		i++;
	}
	return (create_success());
}

static t_error	init_print_mutex(t_waiter *w)
{
	w->print_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (w->print_mutex == NULL)
		return (create_error(ERR_MEMORY));
	if (pthread_mutex_init(w->print_mutex, NULL) != 0)
	{
		free(w->print_mutex);
		return (create_error(ERR_MUTEX_INIT));
	}
	return (create_success());
}

static t_error	init_eat_count(t_waiter *w)
{
	w->eat_count = ft_calloc(w->num_of_philos, sizeof(int));
	if (w->eat_count == NULL)
		return (create_error(ERR_MEMORY));
	return (create_success());
}
