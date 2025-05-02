/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:26:50 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 09:44:20 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_msleep(int ms)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while (1)
	{
		if (elapsed_time_as_ms(start) >= ms)
			break ;
		usleep(100);
	}
}

long	elapsed_time_as_ms(struct timeval start)
{
	struct timeval	now;
	int				elapsed_time;

	gettimeofday(&now, NULL);
	elapsed_time = (now.tv_sec - start.tv_sec) * 1000;
	elapsed_time += (now.tv_usec - start.tv_usec) / 1000;
	return (elapsed_time);
}

struct timeval	get_time_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now);
}
