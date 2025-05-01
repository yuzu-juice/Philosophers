/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:52:59 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/14 18:57:53 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_dec_to_lower_hex(unsigned int u)
{
	if (u < 10)
		return (u + '0');
	else if (u >= 10 && u < 16)
		return (u - 10 + 'a');
	return (0);
}

char	ft_dec_to_upper_hex(unsigned int u)
{
	if (u < 10)
		return (u + '0');
	else if (u >= 10 && u < 16)
		return (u - 10 + 'A');
	return (0);
}
