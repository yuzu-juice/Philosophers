/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:48:56 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/01 20:46:10 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESULT_H
# define RESULT_H

# include <stdbool.h>

typedef struct s_error
{
	bool	is_error;
	char	*message;
}	t_error;

typedef struct s_int_result
{
	int		result;
	t_error	error;
}	t_int_result;

typedef struct s_params
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
}	t_params;

typedef struct s_params_result
{
	t_params	params;
	t_error		error;
}	t_params_result;

#endif
