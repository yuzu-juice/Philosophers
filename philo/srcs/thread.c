/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:42:23 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 14:15:17 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	philo_thinks(t_info *info);
static bool	philo_takes_forks(t_info *info);
static void	philo_eats(t_info *info, bool is_left_fork_id_smaller);
static void	philo_sleeps(t_info *info);

void	*philo_thread(void *arg)
{
	t_info	*info;
	bool	is_left_fork_id_smaller;

	info = (t_info *)arg;
	while (true)
	{
		is_left_fork_id_smaller = philo_takes_forks(info);
		philo_eats(info, is_left_fork_id_smaller);
		philo_sleeps(info);
		philo_thinks(info);
		break ;
	}
	free(info);
	return (NULL);
}

static void	philo_thinks(t_info *info)
{
	ft_msleep(10, info);
	print_is_thinking(info->w, info->philo_id);
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

static void	philo_eats(t_info *info, bool is_left_fork_id_smaller)
{
	t_waiter	*w;
	int			philo_id;

	w = info->w;
	philo_id = info->philo_id;
	print_is_eating(w, philo_id);
	ft_msleep(w->time_to_eat, info);
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
}

static void	philo_sleeps(t_info *info)
{
	ft_msleep(info->w->time_to_sleep, info);
	print_is_sleeping(info->w, info->philo_id);
}
