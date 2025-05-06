/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:13:07 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/06 19:26:41 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_forks(t_waiter *w, int fork_id_1, int fork_id_2)
{
	pthread_mutex_lock(w->forks_mutex);
	w->forks[fork_id_1] = true;
	w->forks[fork_id_2] = true;
	pthread_mutex_unlock(w->forks_mutex);
}

void	put_forks(t_waiter *w, int fork_id_1, int fork_id_2)
{
	pthread_mutex_lock(w->forks_mutex);
	w->forks[fork_id_1] = false;
	w->forks[fork_id_2] = false;
	pthread_mutex_unlock(w->forks_mutex);
}
