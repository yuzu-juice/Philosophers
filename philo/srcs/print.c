/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:30:41 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 13:13:13 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_is_thinking(t_waiter *w, int philo_id)
{
	long	elapsed_time;

	elapsed_time = elapsed_time_as_ms(w->start_time);
	pthread_mutex_lock(w->print_mutex);
	printf("%ld %d is thinking.\n", elapsed_time, philo_id);
	pthread_mutex_unlock(w->print_mutex);
}

void	print_taken_fork(t_waiter *w, int philo_id)
{
	long	elapsed_time;

	elapsed_time = elapsed_time_as_ms(w->start_time);
	pthread_mutex_lock(w->print_mutex);
	printf("%ld %d has taken a fork.\n", elapsed_time, philo_id);
	pthread_mutex_unlock(w->print_mutex);
}

void	print_is_eating(t_waiter *w, int philo_id)
{
	long	elapsed_time;

	elapsed_time = elapsed_time_as_ms(w->start_time);
	pthread_mutex_lock(w->print_mutex);
	printf("%ld %d is eating.\n", elapsed_time, philo_id);
	pthread_mutex_unlock(w->print_mutex);
}

void	print_is_sleeping(t_waiter *w, int philo_id)
{
	long	elapsed_time;

	elapsed_time = elapsed_time_as_ms(w->start_time);
	pthread_mutex_lock(w->print_mutex);
	printf("%ld %d is sleeping.\n", elapsed_time, philo_id);
	pthread_mutex_unlock(w->print_mutex);
}
