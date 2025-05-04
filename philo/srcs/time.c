/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:26:50 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/04 22:04:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_error	ft_msleep(int ms, t_info *info)
{
	long	start;
	bool	has_died;

	start = timestamp();
	has_died = false;
	while (true)
	{
		if (elapsed_time_as_ms(start) >= ms)
			break ;
		pthread_mutex_lock(info->w->is_dead_mutex);
		if (timestamp() - info->last_meal_time >= info->w->time_to_die)
		{
			info->w->is_dead[info->philo_id] = true;
			has_died = true;
		}
		pthread_mutex_unlock(info->w->is_dead_mutex);
		if (has_died)
			return (create_error(ERR_PHILO_DIED));
		if (check_someone_died(info->w) != -1)
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
