/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watchdog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:18:15 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 06:43:53 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	are_all_philos_full(t_waiter *w);

void	*watchdog(void *arg)
{
	t_waiter	*w;
	int			i;
	long		current_meal_time;

	w = (t_waiter *)arg;
	while (true)
	{
		i = 0;
		while (i < w->num_of_philos)
		{
			pthread_mutex_lock(&w->philos[i].philo_mutex);
			current_meal_time = w->philos[i].last_meal_time;
			pthread_mutex_unlock(&w->philos[i].philo_mutex);
			if (timestamp() - current_meal_time >= w->time_to_die)
			{
				print_status(w, i, DIED);
				set_stop_flag(w);
				return (NULL);
			}
			i++;
		}
		if (are_all_philos_full(w))
			return (set_stop_flag(w), NULL);
		usleep(100);
	}
}

static bool	are_all_philos_full(t_waiter *w)
{
	int	i;
	int	current_eat_count;

	if (w->num_of_times_each_philo_must_eat == INT_MAX)
		return (false);
	i = 0;
	while (i < w->num_of_philos)
	{
		pthread_mutex_lock(&w->philos[i].philo_mutex);
		current_eat_count = w->philos[i].eat_count;
		pthread_mutex_unlock(&w->philos[i].philo_mutex);
		if (current_eat_count < w->num_of_times_each_philo_must_eat)
			return (false);
		i++;
	}
	return (true);
}
