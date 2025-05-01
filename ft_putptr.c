/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:28:45 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/12 16:14:04 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_hex_len(unsigned long i)
{
	size_t	len;

	len = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= 16;
		len++;
	}
	return (len);
}

static ssize_t	ft_putptr_hex(unsigned long x)
{
	char	*hex;
	size_t	hex_len;
	size_t	i;

	hex_len = get_hex_len(x);
	hex = malloc(hex_len + 1);
	if (!hex)
		return (-1);
	i = 0;
	while (i < hex_len)
	{
		hex[hex_len - 1 - i] = ft_dec_to_lower_hex(x % 16);
		x >>= 4;
		i++;
	}
	hex[hex_len] = '\0';
	hex_len = ft_putstr(hex);
	free(hex);
	return (hex_len);
}

ssize_t	ft_putptr(uintptr_t p)
{
	ssize_t	result;
	ssize_t	len;

	len = 0;
	result = ft_putstr("0x");
	if (result < 0)
		return (result);
	len += result;
	if (p == 0)
	{
		result = ft_putchar('0');
		if (result < 0)
			return (result);
		len += result;
	}
	else
	{
		result = ft_putptr_hex(p);
		if (result < 0)
			return (result);
		len += result;
	}
	return (len);
}
