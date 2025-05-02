/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:32:08 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 09:32:57 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include <sys/time.h>

void			ft_msleep(int ms);
long			elapsed_time_as_ms(struct timeval start);
struct timeval	get_time_now(void);

#endif
