/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:05:06 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 01:23:24 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include "result.h"
# include "exit.h"
# include "error_messages.h"

# include <pthread.h>
# include <stdio.h>

t_waiter_result	init_waiter(int argc, char **argv);
t_error			philo(t_waiter params);
t_error			create_error(char *message);
t_error			create_success(void);

#endif
