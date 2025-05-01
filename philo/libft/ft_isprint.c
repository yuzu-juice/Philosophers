/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:27:33 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main()
// {
// 	printf("isprint: %d, ft_isprint: %d\n", isprint('a'), ft_isprint('a'));
// 	printf("isprint: %d, ft_isprint: %d\n", isprint('A'), ft_isprint('A'));
// 	printf("isprint: %d, ft_isprint: %d\n", isprint('1'), ft_isprint('1'));
// 	printf("isprint: %d, ft_isprint: %d\n", isprint(0), ft_isprint(0));
// }
