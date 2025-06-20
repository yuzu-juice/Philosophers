/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:32:08 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 07:04:24 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include <sys/time.h>
# include "types.h"

typedef struct s_error	t_error;
typedef struct s_table	t_table;

t_error	ft_msleep(int ms, t_table *t);
long	elapsed_time_as_ms(long start);
long	timestamp(void);

#endif
