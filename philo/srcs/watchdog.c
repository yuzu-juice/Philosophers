/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watchdog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:18:15 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 17:30:25 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
			if (w->is_dead[i])
			{
				pthread_mutex_lock(w->print_mutex);
				printf("Philo %d dead detected\n", i);
				pthread_mutex_unlock(w->print_mutex);
				// exit(0);
			}
			i++;
		}
		usleep(10 * 1000);
	}
	return (NULL);
}
