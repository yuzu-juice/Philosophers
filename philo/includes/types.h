/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:36:21 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/05 17:40:31 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

typedef enum e_exit_failure
{
	FAILURE = EXIT_FAILURE
}	t_exit_failure;

typedef enum e_print_status
{
	TAKEN_FORKS,
	IS_EATING,
	IS_SLEEPING,
	IS_THINKING,
	DIED,
}	t_print_status;

typedef struct s_waiter
{
	long			start_time;
	int				num_of_philos;
	int				num_of_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
	int				*eat_count;
	bool			*is_dead;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*eat_count_mutex;
	pthread_mutex_t	*is_dead_mutex;
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
	int			l_fork_id;
	int			r_fork_id;
	long		last_meal_time;
}	t_info;

typedef struct s_info_result
{
	t_info	*info;
	t_error	error;
}	t_info_result;

#endif