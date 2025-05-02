/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:42:23 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 17:26:44 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_error	philo_thinks(t_info *info);
static bool		philo_takes_forks(t_info *info);
static t_error	philo_eats(t_info *info, bool is_left_fork_id_smaller);
static t_error	philo_sleeps(t_info *info);

void	*philo_thread(void *arg)
{
	t_info	*info;
	bool	is_left_fork_id_smaller;

	info = (t_info *)arg;
	while (true)
	{
		is_left_fork_id_smaller = philo_takes_forks(info);
		if (philo_eats(info, is_left_fork_id_smaller).is_error)
			break ;
		if (philo_sleeps(info).is_error)
			break ;
		if (philo_thinks(info).is_error)
			break ;
	}
	free(info);
	return (NULL);
}

static t_error	philo_thinks(t_info *info)
{
	t_error	error;

	error = ft_msleep(10, info);
	print_is_thinking(info->w, info->philo_id);
	return (error);
}

static bool	philo_takes_forks(t_info *info)
{
	t_waiter	*w;
	bool		is_left_fork_id_smaller;

	w = info->w;
	if (info->left_fork_id < info->right_fork_id)
		is_left_fork_id_smaller = true;
	else
		is_left_fork_id_smaller = false;
	if (is_left_fork_id_smaller)
	{
		pthread_mutex_lock(&(w->forks_mutex[info->left_fork_id]));
		pthread_mutex_lock(&(w->forks_mutex[info->right_fork_id]));
	}
	else
	{
		pthread_mutex_lock(&(w->forks_mutex[info->right_fork_id]));
		pthread_mutex_lock(&(w->forks_mutex[info->left_fork_id]));
	}
	print_taken_fork(w, info->philo_id);
	return (is_left_fork_id_smaller);
}

static t_error	philo_eats(t_info *info, bool is_left_fork_id_smaller)
{
	t_waiter	*w;
	int			philo_id;
	t_error		error;

	w = info->w;
	philo_id = info->philo_id;
	print_is_eating(w, philo_id);
	error = ft_msleep(w->time_to_eat, info);
	if (is_left_fork_id_smaller)
	{
		pthread_mutex_unlock(&(w->forks_mutex[info->right_fork_id]));
		pthread_mutex_unlock(&(w->forks_mutex[info->left_fork_id]));
	}
	else
	{
		pthread_mutex_unlock(&(w->forks_mutex[info->left_fork_id]));
		pthread_mutex_unlock(&(w->forks_mutex[info->right_fork_id]));
	}
	w->eat_count[philo_id]++;
	return (error);
}

static t_error	philo_sleeps(t_info *info)
{
	t_error	error;

	error = ft_msleep(info->w->time_to_sleep, info);
	print_is_sleeping(info->w, info->philo_id);
	return (error);
}
