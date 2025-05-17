/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:32:08 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/07 00:23:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include <sys/time.h>
# include "types.h"

t_error	ft_msleep(int ms, t_waiter *w, int philo_id);
long	elapsed_time_as_ms(long start);
long	timestamp(void);

#endif
