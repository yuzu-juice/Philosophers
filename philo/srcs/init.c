/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:23:08 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 07:04:42 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_error	init_forks(t_table *t)
{
	int	i;

	t->forks = ft_calloc(t->num_of_forks, sizeof(bool));
	if (t->forks == NULL)
		return (create_error(ERR_MEMORY));
	t->forks_mutex = ft_calloc(t->num_of_forks, sizeof(t_mutex));
	if (t->forks_mutex == NULL)
	{
		ft_free(t->forks);
		return (create_error(ERR_MEMORY));
	}
	i = 0;
	while (i < t->num_of_forks)
	{
		if (pthread_mutex_init(&t->forks_mutex[i], NULL) != 0)
		{
			ft_free(t->forks);
			while (--i >= 0)
				pthread_mutex_destroy(&t->forks_mutex[i]);
			ft_free(t->forks_mutex);
			return (create_error(ERR_MUTEX_INIT));
		}
		i++;
	}
	return (create_success());
}
