/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mutex_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 23:54:46 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/19 23:57:23 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	set_stop_flag(t_waiter *w)
{
	pthread_mutex_lock(&w->stop_mutex);
	w->should_stop = true;
	pthread_mutex_unlock(&w->stop_mutex);
}
