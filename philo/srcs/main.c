/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:53:12 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/01 20:48:49 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_exit_failure	print_error_and_return_failure(t_error error);
static t_params_result	init_params(int argc, char **argv);
static t_error			validate_argc(int argc);

int	main(int argc, char **argv)
{
	t_error			error;
	t_params_result	params_result;

	error = validate_argc(argc);
	if (error.is_error)
		return (print_error_and_return_failure(error));
	params_result = init_params(argc, argv);
	if (params_result.error.is_error)
		return (print_error_and_return_failure(params_result.error));
	return (EXIT_SUCCESS);
}

static t_exit_failure print_error_and_return_failure(t_error error)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error.message, 2);
	return (EXIT_FAILURE);
}

static t_error	validate_argc(int argc)
{
	t_error	error;

	error.is_error = FALSE;
	error.message = NULL;
	if (!(argc == 5 || argc == 6))
	{
		error.is_error = TRUE;
		error.message = "Wrong number of args.";
	}
	return (error);
}

static t_params_result	init_params(int argc, char **argv)
{
	t_params		params;
	t_params_result	result;

	result.error.is_error = FALSE;
	result.error.message = NULL;
	params.number_of_philosophers = ft_atoi(argv[1]);
	params.time_to_die = ft_atoi(argv[2]);
	params.time_to_eat = ft_atoi(argv[3]);
	params.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		params.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		params.number_of_times_each_philosopher_must_eat = -1;
	if (params.number_of_philosophers <= 0 || params.time_to_die <= 0
		|| params.time_to_eat <= 0 || params.time_to_sleep <= 0
		|| (argc == 6 && params.number_of_times_each_philosopher_must_eat <= 0))
	{
		result.error.is_error = TRUE;
		result.error.message = "Invalid arguments.";
	}
	else
		result.params = params;
	return (result);
}
