/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_someone_died.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:52:17 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 07:31:48 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

bool	should_stop(t_table *t)
{
	bool	result;

	pthread_mutex_lock(&t->stop_mutex);
	result = t->should_stop;
	pthread_mutex_unlock(&t->stop_mutex);
	return (result);
}
