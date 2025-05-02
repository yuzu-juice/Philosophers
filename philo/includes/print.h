/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:30:58 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 13:13:25 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "result.h"

void	print_is_thinking(t_waiter *w, int philo_id);
void	print_taken_fork(t_waiter *w, int philo_id);
void	print_is_eating(t_waiter *w, int philo_id);
void	print_is_sleeping(t_waiter *w, int philo_id);

#endif
