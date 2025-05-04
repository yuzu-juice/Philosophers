/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:23:08 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/04 21:30:45 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_error	init_forks_mutex(t_waiter *w)
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

t_error	init_print_mutex(t_waiter *w)
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

t_error	init_eat_count(t_waiter *w)
{
	w->eat_count = ft_calloc(w->num_of_philos, sizeof(int));
	if (w->eat_count == NULL)
		return (create_error(ERR_MEMORY));
	w->eat_count_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (w->eat_count_mutex == NULL)
	{
		free(w->eat_count);
		return (create_error(ERR_MEMORY));
	}
	if (pthread_mutex_init(w->eat_count_mutex, NULL) != 0)
	{
		free(w->eat_count);
		free(w->eat_count_mutex);
		return (create_error(ERR_MUTEX_INIT));
	}
	return (create_success());
}

t_error	init_is_dead(t_waiter *w)
{
	w->is_dead = ft_calloc(w->num_of_philos, sizeof(bool));
	if (w->is_dead == NULL)
		return (create_error(ERR_MEMORY));
	w->is_dead_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (w->is_dead_mutex == NULL)
	{
		free(w->is_dead);
		return (create_error(ERR_MEMORY));
	}
	if (pthread_mutex_init(w->is_dead_mutex, NULL) != 0)
	{
		free(w->is_dead);
		free(w->is_dead_mutex);
		return (create_error(ERR_MUTEX_INIT));
	}
	return (create_success());
}
