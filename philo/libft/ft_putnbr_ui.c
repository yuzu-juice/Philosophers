/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:47:12 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/10 17:48:46 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_ui(unsigned int u)
{
	ssize_t	result;
	ssize_t	len;

	len = 0;
	if (u >= 10)
	{
		result = ft_putnbr_ui(u / 10);
		if (result < 0)
			return (result);
		len += result;
	}
	result = ft_putchar((u % 10) + '0');
	if (result < 0)
		return (result);
	len += result;
	return (len);
}
