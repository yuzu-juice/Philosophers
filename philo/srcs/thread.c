/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:42:23 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 13:15:45 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	philo_takes_forks_and_eats(t_info *info);
static void	philo_sleeps(t_info *info);

void	*philo_thread(void *arg)
{
	t_info		*info;

	info = (t_info *)arg;
	while (true)
	{
		philo_takes_forks_and_eats(info);
		philo_sleeps(info);
	}
	free(info);
	return (NULL);
}

static void	philo_takes_forks_and_eats(t_info *info)
{
	t_waiter	*w;
	int			fork_id_smaller;
	int			fork_id_bigger;

	w = info->w;
	if (info->left_fork_id < info->right_fork_id)
	{
		fork_id_smaller = info->left_fork_id;
		fork_id_bigger = info->right_fork_id;
	}
	else
	{
		fork_id_smaller = info->right_fork_id;
		fork_id_bigger = info->left_fork_id;
	}
	print_is_thinking(w, info->philo_id);
	pthread_mutex_lock(&(w->forks_mutex[fork_id_smaller]));
	pthread_mutex_lock(&(w->forks_mutex[fork_id_bigger]));
	print_taken_fork(w, info->philo_id);
	print_is_eating(w, info->philo_id);
	ft_msleep(w->time_to_eat);
	pthread_mutex_unlock(&(w->forks_mutex[fork_id_bigger]));
	pthread_mutex_unlock(&(w->forks_mutex[fork_id_smaller]));
}

static void	philo_sleeps(t_info *info)
{
	t_waiter	*w;
	int			time_to_eat;

	w = info->w;
	time_to_eat = w->time_to_eat;
	print_is_sleeping(w, info->philo_id);
	ft_msleep(time_to_eat);
}
