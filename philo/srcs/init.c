/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:23:08 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/05 18:31:58 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_error	init_forks(t_waiter *w)
{
	w->forks = ft_calloc(w->num_of_forks, sizeof(t_mutex));
	if (w->forks == NULL)
		return (create_error(ERR_MEMORY));
	w->forks_mutex = ft_calloc(1, sizeof(t_mutex));
	if (w->forks_mutex == NULL)
	{
		ft_free(w->forks);
		return (create_error(ERR_MEMORY));
	}
	if (pthread_mutex_init(w->forks_mutex, NULL)!= 0)
	{
		ft_free(w->forks);
		ft_free(w->forks_mutex);
		return (create_error(ERR_MUTEX_INIT));
	}
	return (create_success());
}

t_error	init_print(t_waiter *w)
{
	w->print_mutex = ft_calloc(1, sizeof(t_mutex));
	if (w->print_mutex == NULL)
		return (create_error(ERR_MEMORY));
	if (pthread_mutex_init(w->print_mutex, NULL) != 0)
	{
		ft_free(w->print_mutex);
		return (create_error(ERR_MUTEX_INIT));
	}
	return (create_success());
}

t_error	init_eat_count(t_waiter *w)
{
	w->eat_count = ft_calloc(w->num_of_philos, sizeof(int));
	if (w->eat_count == NULL)
		return (create_error(ERR_MEMORY));
	w->eat_count_mutex = ft_calloc(1, sizeof(t_mutex));
	if (w->eat_count_mutex == NULL)
	{
		ft_free(w->eat_count);
		return (create_error(ERR_MEMORY));
	}
	if (pthread_mutex_init(w->eat_count_mutex, NULL) != 0)
	{
		ft_free(w->eat_count);
		ft_free(w->eat_count_mutex);
		return (create_error(ERR_MUTEX_INIT));
	}
	return (create_success());
}

t_error	init_is_dead(t_waiter *w)
{
	w->is_dead = ft_calloc(w->num_of_philos, sizeof(bool));
	if (w->is_dead == NULL)
		return (create_error(ERR_MEMORY));
	w->is_dead_mutex = ft_calloc(1, sizeof(t_mutex));
	if (w->is_dead_mutex == NULL)
	{
		ft_free(w->is_dead);
		return (create_error(ERR_MEMORY));
	}
	if (pthread_mutex_init(w->is_dead_mutex, NULL) != 0)
	{
		ft_free(w->is_dead);
		ft_free(w->is_dead_mutex);
		return (create_error(ERR_MUTEX_INIT));
	}
	return (create_success());
}
