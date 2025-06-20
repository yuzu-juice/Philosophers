/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:42:23 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 06:39:47 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_error	philo_thinks(t_waiter *w, int philo_id);
static void		philo_takes_forks(t_waiter *w, int philo_id);
static t_error	philo_eats(t_waiter *w, int philo_id);
static t_error	philo_sleeps(t_waiter *w, int philo_id);

void	*philo_thread(void *arg)
{
	t_thread_arg	*thread_arg;
	t_philo			*philo;
	t_waiter		*w;
	int				philo_id;

	thread_arg = (t_thread_arg *)arg;
	w = thread_arg->w;
	philo_id = thread_arg->philo_id;
	philo = &w->philos[philo_id];
	while (true)
	{
		philo_takes_forks(w, philo_id);
		if (check_someone_died(w) != -1)
		{
			put_forks(w, philo->l_fork_id, philo->r_fork_id);
			break ;
		}
		if (philo_eats(w, philo_id).is_error
			|| check_someone_died(w) != -1 || philo_sleeps(w, philo_id).is_error
			|| check_someone_died(w) != -1 || philo_thinks(w, philo_id).is_error
			|| check_someone_died(w) != -1)
			break ;
	}
	return (NULL);
}

// Wait until the philosopher can take forks
static t_error	philo_thinks(t_waiter *w, int philo_id)
{
	t_error	error;

	print_status(w, philo_id, IS_THINKING);
	error = ft_msleep(1, w);
	return (error);
}

static void	philo_takes_forks(t_waiter *w, int philo_id)
{
	t_philo		*philo;

	philo = &w->philos[philo_id];
	take_forks(w, philo->l_fork_id, philo->r_fork_id);
	print_status(w, philo_id, TAKEN_FORKS);
}

static t_error	philo_eats(t_waiter *w, int philo_id)
{
	t_error	error;
	t_philo	*philo;

	philo = &w->philos[philo_id];
	pthread_mutex_lock(&philo->philo_mutex);
	philo->last_meal_time = timestamp();
	pthread_mutex_unlock(&philo->philo_mutex);
	print_status(w, philo_id, IS_EATING);
	error = ft_msleep(w->time_to_eat, w);
	put_forks(w, philo->l_fork_id, philo->r_fork_id);
	pthread_mutex_lock(&philo->philo_mutex);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->philo_mutex);
	return (error);
}

static t_error	philo_sleeps(t_waiter *w, int philo_id)
{
	t_error	error;

	print_status(w, philo_id, IS_SLEEPING);
	error = ft_msleep(w->time_to_sleep, w);
	return (error);
}
