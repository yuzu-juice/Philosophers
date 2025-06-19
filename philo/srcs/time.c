/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:26:50 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/19 20:49:35 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_error	ft_msleep(int ms, t_waiter *w, int philo_id)
{
	long	start;
	t_philo	*philo;

	philo = &w->philos[philo_id];
	start = timestamp();
	while (true)
	{
		if (elapsed_time_as_ms(start) >= ms)
			break ;
		if (timestamp() - philo->last_meal_time >= w->time_to_die)
		{
			w->philos[philo_id].is_dead = true;
			return (create_error(ERR_PHILO_DIED));
		}
		if (check_someone_died(w) != -1)
			return (create_error(ERR_PHILO_DIED));
		usleep(1000);
	}
	return (create_success());
}

long	elapsed_time_as_ms(long start)
{
	long	elapsed_time;

	elapsed_time = timestamp() - start;
	return (elapsed_time);
}

long	timestamp(void)
{
	struct timeval	now;
	long			timestamp;

	gettimeofday(&now, NULL);
	timestamp = now.tv_sec * 1000;
	timestamp += now.tv_usec / 1000;
	return (timestamp);
}
