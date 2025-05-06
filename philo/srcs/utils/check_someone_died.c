/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_someone_died.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:52:17 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/06 19:00:52 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	check_someone_died(t_waiter *w)
{
	int	i;
	int	dead_philo_id;

	i = 0;
	dead_philo_id = -1;
	while (i < w->num_of_philos)
	{
		if (w->philos[i].is_dead)
		{
			dead_philo_id = i;
			break ;
		}
		i++;
	}
	return (dead_philo_id);
}
