/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:13:07 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 08:13:19 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	get_fork_order(int fork_1, int fork_2, int *first, int *second);

void	take_forks(t_waiter *w, int fork_1, int fork_2)
{
	int	first_fork_to_take;
	int	second_fork_to_take;

	get_fork_order(fork_1, fork_2, &first_fork_to_take, &second_fork_to_take);
	while (true)
	{
		pthread_mutex_lock(&w->forks_mutex[first_fork_to_take]);
		if (!w->forks[first_fork_to_take])
		{
			pthread_mutex_lock(&w->forks_mutex[second_fork_to_take]);
			if (!w->forks[second_fork_to_take])
			{
				w->forks[first_fork_to_take] = true;
				w->forks[second_fork_to_take] = true;
				pthread_mutex_unlock(&w->forks_mutex[second_fork_to_take]);
				pthread_mutex_unlock(&w->forks_mutex[first_fork_to_take]);
				return ;
			}
			pthread_mutex_unlock(&w->forks_mutex[second_fork_to_take]);
		}
		pthread_mutex_unlock(&w->forks_mutex[first_fork_to_take]);
	}
}

void	put_forks(t_waiter *w, int fork_1, int fork_2)
{
	int	first_fork_to_put;
	int	second_fork_to_put;

	get_fork_order(fork_1, fork_2, &first_fork_to_put, &second_fork_to_put);
	pthread_mutex_lock(&w->forks_mutex[first_fork_to_put]);
	pthread_mutex_lock(&w->forks_mutex[second_fork_to_put]);
	w->forks[first_fork_to_put] = false;
	w->forks[second_fork_to_put] = false;
	pthread_mutex_unlock(&w->forks_mutex[first_fork_to_put]);
	pthread_mutex_unlock(&w->forks_mutex[second_fork_to_put]);
}

static void	get_fork_order(int fork_1, int fork_2, int *first, int *second)
{
	if (fork_1 < fork_2)
	{
		*first = fork_1;
		*second = fork_2;
	}
	else
	{
		*first = fork_2;
		*second = fork_1;
	}
}
