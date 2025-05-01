/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 23:23:59 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/06 23:24:41 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_len(int n)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

ssize_t	ft_putnbr(int n)
{
	ssize_t	result;
	ssize_t	len;

	len = nbr_len(n);
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		result = ft_putchar('-');
		if (result < 0)
			return (result);
		n *= -1;
	}
	if (n >= 10)
	{
		result = ft_putnbr(n / 10);
		if (result < 0)
			return (result);
	}
	result = ft_putchar((n % 10) + '0');
	if (result < 0)
		return (result);
	return (len);
}
