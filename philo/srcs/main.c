/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:53:12 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 08:17:58 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_exit_failure	print_error_and_return_failure(t_error error);
static t_error			validate_argc(int argc);

int	main(int argc, char **argv)
{
	t_error			error;
	t_table_result	table_result;

	error = validate_argc(argc);
	if (error.is_error)
		return (print_error_and_return_failure(error));
	table_result = init_table(argc, argv);
	if (table_result.error.is_error)
		return (print_error_and_return_failure(table_result.error));
	error = philo(table_result.t);
	if (error.is_error)
	{
		cleanup_table(&table_result.t);
		return (print_error_and_return_failure(error));
	}
	cleanup_table(&table_result.t);
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
