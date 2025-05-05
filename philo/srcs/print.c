/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:30:41 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/05 11:41:11 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_status(t_waiter *w, int philo_id, t_print_status s)
{
	long	elapsed_time;

	elapsed_time = elapsed_time_as_ms(w->start_time);
	pthread_mutex_lock(w->print_mutex);
	if (s == TAKEN_FORKS)
		printf("%ld %d has taken a fork\n", elapsed_time, philo_id);
	else if (s == IS_EATING)
		printf("%ld %d is eating\n", elapsed_time, philo_id);
	else if (s == IS_SLEEPING)
		printf("%ld %d is sleeping\n", elapsed_time, philo_id);
	else if (s == IS_THINKING)
		printf("%ld %d is thinking\n", elapsed_time, philo_id);
	else if (s == DIED)
		printf("%ld %d died\n", elapsed_time, philo_id);
	pthread_mutex_unlock(w->print_mutex);
}
