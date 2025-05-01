/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:50:32 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 00:53:18 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_error	create_error(char *message)
{
	t_error	error;

	error.is_error = true;
	error.message = message;
	return (error);
}

t_error	create_success(void)
{
	t_error	error;

	error.is_error = false;
	error.message = NULL;
	return (error);
}
