/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mutex_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 23:54:46 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 07:00:47 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	set_stop_flag(t_table *t)
{
	pthread_mutex_lock(&t->stop_mutex);
	t->should_stop = true;
	pthread_mutex_unlock(&t->stop_mutex);
}
