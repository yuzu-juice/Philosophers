/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:05:06 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/04 00:18:59 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "result.h"
# include "exit.h"
# include "error_messages.h"
# include "utils.h"
# include "waiter.h"
# include "thread.h"
# include "print.h"
# include "time.h"
# include "forks.h"

# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>

t_waiter_result	init_waiter(int argc, char **argv);
void			cleanup_waiter(t_waiter *w);
t_error			philo(t_waiter params);
t_error			create_error(char *msg);
t_error			create_success(void);

#endif
