/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:08:57 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/12 15:46:38 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_hex_len(unsigned int i)
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

ssize_t	ft_puthex(unsigned long x, int is_lower)
{
	char	*hex;
	size_t	hex_len;
	size_t	i;
	ssize_t	result;

	hex_len = get_hex_len(x);
	hex = malloc(hex_len + 1);
	if (!hex)
		return (-1);
	i = 0;
	while (i < hex_len)
	{
		if (is_lower)
			hex[hex_len - 1 - i] = ft_dec_to_lower_hex(x % 16);
		else
			hex[hex_len - 1 - i] = ft_dec_to_upper_hex(x % 16);
		x >>= 4;
		i++;
	}
	hex[hex_len] = '\0';
	result = ft_putstr(hex);
	free(hex);
	return (result);
}
