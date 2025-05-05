/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:32:08 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/05 17:40:25 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include <sys/time.h>
# include "types.h"

t_error	ft_msleep(int ms, t_info *info);
long	elapsed_time_as_ms(long start);
long	timestamp(void);

#endif
