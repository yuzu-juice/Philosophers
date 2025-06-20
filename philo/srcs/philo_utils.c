/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 06:50:51 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 07:02:58 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_error	solo_philo(t_table *t)
{
	print_status(t, 0, TAKEN_FORK);
	ft_msleep(t->time_to_die, t);
	print_status(t, 0, DIED);
	return (create_success());
}
