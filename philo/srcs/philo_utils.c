/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 06:50:51 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 06:51:48 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_error	solo_philo(t_waiter *w)
{
	print_status(w, 0, TAKEN_FORK);
	ft_msleep(w->time_to_die, w);
	print_status(w, 0, DIED);
	return (create_success());
}
