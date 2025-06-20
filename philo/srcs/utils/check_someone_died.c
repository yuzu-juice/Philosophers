/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_someone_died.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:52:17 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 07:00:47 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	check_someone_died(t_table *t)
{
	int	dead_philo_id;

	dead_philo_id = -1;
	if (should_stop(t))
		return (0);
	return (dead_philo_id);
}

bool	should_stop(t_table *t)
{
	bool	result;

	pthread_mutex_lock(&t->stop_mutex);
	result = t->should_stop;
	pthread_mutex_unlock(&t->stop_mutex);
	return (result);
}
