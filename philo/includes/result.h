/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:48:56 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 09:41:49 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESULT_H
# define RESULT_H

# include "philo.h"
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_waiter
{
	struct timeval	start_time;
	int				num_of_philos;
	int				num_of_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	*print_mutex;
}	t_waiter;

typedef struct s_error
{
	bool	is_error;
	char	*msg;
}	t_error;

typedef struct s_int_result
{
	int		result;
	t_error	error;
}	t_int_result;

typedef struct s_waiter_result
{
	t_waiter	w;
	t_error		error;
}	t_waiter_result;

typedef struct s_pthread_t_ptr_result
{
	pthread_t	*tid;
	t_error		error;
}	t_pthread_ptr_result;

typedef struct s_info
{
	t_waiter	*w;
	int			philo_id;
	int			left_fork_id;
	int			right_fork_id;
}	t_info;

typedef struct s_info_result
{
	t_info	*info;
	t_error	error;
}	t_info_result;

#endif
