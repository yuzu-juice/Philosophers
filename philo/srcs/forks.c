/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:13:07 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/07 00:33:20 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_forks(t_waiter *w, int fork_id_1, int fork_id_2)
{
	int	first_fork_to_take;
	int	second_fork_to_take;

	if (fork_id_1 < fork_id_2)
	{
		first_fork_to_take = fork_id_1;
		second_fork_to_take = fork_id_2;
	}
	else
	{
		first_fork_to_take = fork_id_2;
		second_fork_to_take = fork_id_1;
	}
	pthread_mutex_lock(&w->forks_mutex[first_fork_to_take]);
	w->forks[first_fork_to_take] = true;
	pthread_mutex_lock(&w->forks_mutex[second_fork_to_take]);
	w->forks[second_fork_to_take] = true;
}

void	put_forks(t_waiter *w, int fork_id_1, int fork_id_2)
{
	int	first_fork_to_put;
	int	second_fork_to_put;

	if (fork_id_1 < fork_id_2)
	{
		first_fork_to_put = fork_id_1;
		second_fork_to_put = fork_id_2;
	}
	else
	{
		first_fork_to_put = fork_id_2;
		second_fork_to_put = fork_id_1;
	}
	w->forks[first_fork_to_put] = false;
	pthread_mutex_unlock(&w->forks_mutex[first_fork_to_put]);
	w->forks[second_fork_to_put] = false;
	pthread_mutex_unlock(&w->forks_mutex[second_fork_to_put]);
}
