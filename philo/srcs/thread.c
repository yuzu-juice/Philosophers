/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:42:23 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/06 19:27:28 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_error	philo_thinks(t_waiter *w, int philo_id);
static bool		philo_takes_forks(t_waiter *w, int philo_id);
static t_error	philo_eats(t_waiter *w, int philo_id, bool is_l_fork_id_smaller);
static t_error	philo_sleeps(t_waiter *w, int philo_id);

void	*philo_thread(void *arg)
{
	t_thread_arg	*thread_arg;
	t_philo			*philo;
	t_waiter		*w;
	bool			is_l_fork_id_smaller;
	int				philo_id;

	thread_arg = (t_thread_arg *)arg;
	w = thread_arg->w;
	philo_id = thread_arg->philo_id;
	philo = &w->philos[philo_id];
	while (true)
	{
		is_l_fork_id_smaller = philo_takes_forks(w, philo->philo_id);
		if (check_someone_died(w) != -1)
		{
			if (is_l_fork_id_smaller)
				put_forks(w, philo->l_fork_id, philo->r_fork_id);
			else
				put_forks(w, philo->r_fork_id, philo->l_fork_id);
			break ;
		}
		if (philo_eats(w, philo->philo_id, is_l_fork_id_smaller).is_error
			|| check_someone_died(w) != -1 || philo_sleeps(w, philo->philo_id).is_error
			|| check_someone_died(w) != -1 || philo_thinks(w, philo->philo_id).is_error
			|| check_someone_died(w) != -1)
			break ;
	}
	return (NULL);
}

static t_error	philo_thinks(t_waiter *w, int philo_id)
{
	t_error	error;

	print_status(w, philo_id, IS_THINKING);
	// Wait until the philosopher can take forks
	error = ft_msleep(1, w, philo_id);
	return (error);
}

static bool	philo_takes_forks(t_waiter *w, int philo_id)
{
	bool		is_l_fork_id_smaller;
	t_philo		*philo;

	philo = &w->philos[philo_id];
	if (philo->l_fork_id < philo->r_fork_id)
		is_l_fork_id_smaller = true;
	else
		is_l_fork_id_smaller = false;
	if (is_l_fork_id_smaller)
		take_forks(w, philo->l_fork_id, philo->r_fork_id);
	else
		take_forks(w, philo->r_fork_id, philo->l_fork_id);
	print_status(w, philo_id, TAKEN_FORKS);
	return (is_l_fork_id_smaller);
}

static t_error	philo_eats(t_waiter *w, int philo_id, bool is_l_fork_id_smaller)
{
	t_error	error;
	t_philo	*philo;

	philo = &w->philos[philo_id];
	philo->last_meal_time = timestamp();
	print_status(w, philo_id, IS_EATING);
	error = ft_msleep(w->time_to_eat, w, philo_id);
	if (is_l_fork_id_smaller)
		put_forks(w, philo->l_fork_id, philo->r_fork_id);
	else
		put_forks(w, philo->r_fork_id, philo->l_fork_id);
	philo->eat_count++;
	return (error);
}

static t_error	philo_sleeps(t_waiter *w, int philo_id)
{
	t_error	error;

	print_status(w, philo_id, IS_SLEEPING);
	error = ft_msleep(w->time_to_sleep, w, philo_id);
	return (error);
}
