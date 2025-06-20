/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:26:50 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 06:53:57 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_error	ft_msleep(int ms, t_waiter *w)
{
	long	start;

	start = timestamp();
	while (true)
	{
		if (should_stop(w))
			return (create_error(ERR_PHILO_DIED));
		if (elapsed_time_as_ms(start) >= ms)
			break ;
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
