/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:23:08 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/19 20:26:02 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_error	init_forks(t_waiter *w)
{
	int	i;

	w->forks = ft_calloc(w->num_of_forks, sizeof(bool));
	if (w->forks == NULL)
		return (create_error(ERR_MEMORY));
	w->forks_mutex = ft_calloc(w->num_of_forks, sizeof(t_mutex));
	if (w->forks_mutex == NULL)
	{
		ft_free(w->forks);
		return (create_error(ERR_MEMORY));
	}
	i = 0;
	while (i < w->num_of_forks)
	{
		if (pthread_mutex_init(&w->forks_mutex[i], NULL) != 0)
		{
			ft_free(w->forks);
			while (--i >= 0)
				pthread_mutex_destroy(&w->forks_mutex[i]);
			ft_free(w->forks_mutex);
			return (create_error(ERR_MUTEX_INIT));
		}
		i++;
	}
	return (create_success());
}
