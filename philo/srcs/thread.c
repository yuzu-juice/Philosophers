/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:42:23 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/05 18:50:08 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_error	philo_thinks(t_info *info);
static bool		philo_takes_forks(t_info *info);
static t_error	philo_eats(t_info *info, bool is_l_fork_id_smaller);
static t_error	philo_sleeps(t_info *info);

void	*philo_thread(void *arg)
{
	t_info		*info;
	t_waiter	*w;
	bool		is_l_fork_id_smaller;

	info = (t_info *)arg;
	w = info->w;
	while (true)
	{
		is_l_fork_id_smaller = philo_takes_forks(info);
		if (check_someone_died(w) != -1)
		{
			if (is_l_fork_id_smaller)
				put_forks(w->forks, w->forks_mutex, info->l_fork_id, info->r_fork_id);
			else
				put_forks(w->forks, w->forks_mutex, info->r_fork_id, info->l_fork_id);
			break ;
		}
		if (philo_eats(info, is_l_fork_id_smaller).is_error
			|| check_someone_died(w) != -1 || philo_sleeps(info).is_error
			|| check_someone_died(w) != -1 || philo_thinks(info).is_error
			|| check_someone_died(w) != -1)
			break ;
	}
	ft_free(info);
	return (NULL);
}

static t_error	philo_thinks(t_info *info)
{
	t_error	error;

	print_status(info->w, info->philo_id, IS_THINKING);
	// Wait until the philosopher can take forks
	error = ft_msleep(1, info);
	return (error);
}

static bool	philo_takes_forks(t_info *info)
{
	t_waiter	*w;
	bool		is_l_fork_id_smaller;

	w = info->w;
	if (info->l_fork_id < info->r_fork_id)
		is_l_fork_id_smaller = true;
	else
		is_l_fork_id_smaller = false;
	if (is_l_fork_id_smaller)
		take_forks(w->forks, w->forks_mutex, info->l_fork_id, info->r_fork_id);
	else
		take_forks(w->forks, w->forks_mutex, info->r_fork_id, info->l_fork_id);
	print_status(w, info->philo_id, TAKEN_FORKS);
	return (is_l_fork_id_smaller);
}

static t_error	philo_eats(t_info *info, bool is_l_fork_id_smaller)
{
	t_waiter	*w;
	int			philo_id;
	t_error		error;

	w = info->w;
	philo_id = info->philo_id;
	info->last_meal_time = timestamp();
	print_status(w, philo_id, IS_EATING);
	error = ft_msleep(w->time_to_eat, info);
	if (is_l_fork_id_smaller)
		put_forks(w->forks, w->forks_mutex, info->l_fork_id, info->r_fork_id);
	else
		put_forks(w->forks, w->forks_mutex, info->r_fork_id, info->l_fork_id);
	w->eat_count[philo_id]++;
	return (error);
}

static t_error	philo_sleeps(t_info *info)
{
	t_error	error;

	print_status(info->w, info->philo_id, IS_SLEEPING);
	error = ft_msleep(info->w->time_to_sleep, info);
	return (error);
}
