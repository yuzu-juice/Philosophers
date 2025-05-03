/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:13:07 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/04 00:29:55 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_forks(pthread_mutex_t *forks_mutex, int fork_id_1, int fork_id_2)
{
	pthread_mutex_lock(&forks_mutex[fork_id_1]);
	pthread_mutex_lock(&forks_mutex[fork_id_2]);
}

void	put_forks(pthread_mutex_t *forks_mutex, int fork_id_1, int fork_id_2)
{
	pthread_mutex_unlock(&forks_mutex[fork_id_1]);
	pthread_mutex_unlock(&forks_mutex[fork_id_2]);
}
