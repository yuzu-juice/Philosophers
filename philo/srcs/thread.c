/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:42:23 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 09:41:20 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_thread(void *arg)
{
	t_info		*info;
	t_waiter	*w;
	int			fork_id_smaller;
	int			fork_id_bigger;

	info = (t_info *)arg;
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
	pthread_mutex_lock(&(w->forks_mutex[fork_id_smaller]));
	pthread_mutex_lock(&(w->forks_mutex[fork_id_bigger]));
	ft_msleep(w->time_to_eat);
	print_taken_fork(w, info->philo_id);
	pthread_mutex_unlock(&(w->forks_mutex[fork_id_bigger]));
	pthread_mutex_unlock(&(w->forks_mutex[fork_id_smaller]));
	free(info);
	return (NULL);
}
