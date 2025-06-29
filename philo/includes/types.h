/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:36:21 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 19:00:06 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

typedef pthread_mutex_t	t_mutex;

typedef enum e_exit_failure
{
	FAILURE = EXIT_FAILURE
}	t_exit_failure;

typedef enum e_print_status
{
	TAKEN_FORK,
	IS_EATING,
	IS_SLEEPING,
	IS_THINKING,
	DIED,
}	t_print_status;

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

typedef struct s_philo
{
	int			philo_id;
	int			l_fork_id;
	int			r_fork_id;
	int			eat_count;
	long		last_meal_time;
	t_mutex		philo_mutex;
}	t_philo;

typedef struct s_info_result
{
	t_philo	*philo;
	t_error	error;
}	t_philo_result;

typedef struct s_table
{
	t_philo	*philos;
	long	start_time;
	int		num_of_philos;
	int		num_of_forks;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_times_each_philo_must_eat;
	bool	*forks;
	bool	should_stop;
	t_mutex	*forks_mutex;
	t_mutex	print_mutex;
	t_mutex	stop_mutex;
}	t_table;

typedef struct s_table_result
{
	t_table	t;
	t_error	error;
}	t_table_result;

typedef struct s_thread_arg
{
	t_table	*t;
	int		philo_id;
}	t_thread_arg;

typedef struct s_pthread_t_ptr_result
{
	pthread_t		*tid;
	t_thread_arg	*args;
	t_error			error;
}	t_pthread_ptr_result;

#endif
