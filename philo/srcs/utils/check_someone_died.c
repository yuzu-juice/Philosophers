/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_someone_died.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:52:17 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/03 20:20:54 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

bool	check_someone_died(t_waiter *w)
{
	int	i;

	i = 0;
	while (i < w->num_of_philos)
	{
		if (w->is_dead[i])
		{
			pthread_mutex_lock(w->print_mutex);
			printf("Philo %d dead detected\n", i);
			pthread_mutex_unlock(w->print_mutex);
			return (true);
		}
		i++;
	}
	return (false);
}
