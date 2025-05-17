/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:24:11 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/06 18:58:24 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAITER_H
# define WAITER_H

# include "types.h"

t_error	init_forks(t_waiter *w);
t_error	init_print(t_waiter *w);

#endif
