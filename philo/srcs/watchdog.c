/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watchdog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:18:15 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/05 01:51:22 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool are_all_philos_full(t_waiter *w);

void *watchdog(void *arg)
{
	t_waiter	*w;
	int			dead_philo_id;

	w = (t_waiter *)arg;
	while (true)
	{
		dead_philo_id = check_someone_died(w);
		if (dead_philo_id != -1)
		{
			usleep(1000);
			print_died(w, dead_philo_id);
			break ;
		}
		if (are_all_philos_full(w))
		{
			pthread_mutex_lock(w->is_dead_mutex);
			w->is_dead[0] = true;
			pthread_mutex_unlock(w->is_dead_mutex);
			break ;
		}
		usleep(100);
	}
	return (NULL);
}

static bool	are_all_philos_full(t_waiter *w)
{
	int	i;

	i = 0;
	while (i < w->num_of_philos)
	{
		if (w->eat_count[i] < w->num_of_times_each_philo_must_eat)
			return (false);
		i++;
	}
	return (true);
}
