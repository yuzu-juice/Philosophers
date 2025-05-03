/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:24:11 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/03 20:26:26 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAITER_H
# define WAITER_H

# include "result.h"

t_error	init_forks_mutex(t_waiter *w);
t_error	init_print_mutex(t_waiter *w);
t_error	init_eat_count(t_waiter *w);
t_error	init_is_dead(t_waiter *w);

#endif
