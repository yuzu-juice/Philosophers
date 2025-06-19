/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 00:00:15 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 00:00:42 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	free_t_pthread_ptr(t_pthread_ptr_result *ptr)
{
	if (ptr == NULL)
		return ;
	ft_free(ptr->tid);
	ft_free(ptr->args);
}
