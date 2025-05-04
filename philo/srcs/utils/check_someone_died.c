/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_someone_died.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:52:17 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/05 01:17:07 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	check_someone_died(t_waiter *w)
{
	int	i;
	int	dead_philo_id;

	i = 0;
	dead_philo_id = -1;
	pthread_mutex_lock(w->is_dead_mutex);
	while (i < w->num_of_philos)
	{
		if (w->is_dead[i])
		{
			dead_philo_id = i;
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(w->is_dead_mutex);
	return (dead_philo_id);
}
