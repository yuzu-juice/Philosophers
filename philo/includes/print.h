/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:30:58 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/05 11:41:05 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "result.h"

typedef enum e_print_status
{
	TAKEN_FORKS,
	IS_EATING,
	IS_SLEEPING,
	IS_THINKING,
	DIED,
}	t_print_status;

void	print_status(t_waiter *w, int philo_id, t_print_status s);

#endif
