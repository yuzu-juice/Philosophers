/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 23:18:41 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/06 23:25:45 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putstr(char *s)
{
	ssize_t	result;
	ssize_t	len;

	len = 0;
	while (*s)
	{
		result = ft_putchar(*s);
		if (result < 0)
			return (result);
		len += result;
		s++;
	}
	return (len);
}
