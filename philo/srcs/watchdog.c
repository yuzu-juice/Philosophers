/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watchdog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:18:15 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 07:03:47 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	are_all_philos_full(t_table *t);

void	*watchdog(void *arg)
{
	t_table	*t;
	int		i;
	long	current_meal_time;

	t = (t_table *)arg;
	while (true)
	{
		i = 0;
		while (i < t->num_of_philos)
		{
			pthread_mutex_lock(&t->philos[i].philo_mutex);
			current_meal_time = t->philos[i].last_meal_time;
			pthread_mutex_unlock(&t->philos[i].philo_mutex);
			if (timestamp() - current_meal_time >= t->time_to_die)
			{
				print_status(t, i, DIED);
				set_stop_flag(t);
				return (NULL);
			}
			i++;
		}
		if (are_all_philos_full(t))
			return (set_stop_flag(t), NULL);
		usleep(100);
	}
}

static bool	are_all_philos_full(t_table *t)
{
	int	i;
	int	current_eat_count;

	if (t->num_of_times_each_philo_must_eat == INT_MAX)
		return (false);
	i = 0;
	while (i < t->num_of_philos)
	{
		pthread_mutex_lock(&t->philos[i].philo_mutex);
		current_eat_count = t->philos[i].eat_count;
		pthread_mutex_unlock(&t->philos[i].philo_mutex);
		if (current_eat_count < t->num_of_times_each_philo_must_eat)
			return (false);
		i++;
	}
	return (true);
}
