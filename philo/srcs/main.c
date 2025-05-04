/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:53:12 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/04 23:51:39 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_exit_failure	print_error_and_return_failure(t_error error);
static t_error			validate_argc(int argc);

int	main(int argc, char **argv)
{
	t_error			error;
	t_waiter_result	waiter_result;

	error = validate_argc(argc);
	if (error.is_error)
		return (print_error_and_return_failure(error));
	waiter_result = init_waiter(argc, argv);
	if (waiter_result.error.is_error)
		return (print_error_and_return_failure(waiter_result.error));
	error = philo(waiter_result.w);
	if (error.is_error)
	{
		cleanup_waiter(&waiter_result.w);
		return (print_error_and_return_failure(error));
	}
	cleanup_waiter(&waiter_result.w);
	return (EXIT_SUCCESS);
}

static t_exit_failure	print_error_and_return_failure(t_error error)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error.msg, 2);
	return (EXIT_FAILURE);
}

static t_error	validate_argc(int argc)
{
	if (!(argc == 5 || argc == 6))
		return (create_error(ERR_WRONG_ARGC));
	return (create_success());
}
