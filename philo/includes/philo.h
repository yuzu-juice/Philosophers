/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:05:06 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 08:17:51 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "error_messages.h"
# include "utils.h"
# include "table.h"
# include "thread.h"
# include "print.h"
# include "time.h"
# include "forks.h"
# include "types.h"

# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>

t_table_result	init_table(int argc, char **argv);
void			cleanup_table(t_table *t);
t_error			philo(t_table params);
t_error			solo_philo(t_table *t);
t_error			create_error(char *msg);
t_error			create_success(void);

#endif
