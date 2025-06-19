/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watchdog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:18:15 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/19 23:56:34 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	are_all_philos_full(t_waiter *w);

void	*watchdog(void *arg)
{
	t_waiter	*w;
	int			i;

	w = (t_waiter *)arg;
	while (true)
	{
		i = 0;
		while (i < w->num_of_philos)
		{
			if (timestamp() - w->philos[i].last_meal_time >= w->time_to_die)
			{
				print_status(w, i, DIED);
				set_stop_flag(w);
				return (NULL);
			}
			i++;
		}
		if (are_all_philos_full(w))
		{
			set_stop_flag(w);
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
		if (w->philos[i].eat_count < w->num_of_times_each_philo_must_eat)
			return (false);
		i++;
	}
	return (true);
}
