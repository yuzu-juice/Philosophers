/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:27:33 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main()
// {
// 	printf("isascii: %d, ft_isascii: %d\n", isascii('a'), ft_isascii('a'));
// 	printf("isascii: %d, ft_isascii: %d\n", isascii('A'), ft_isascii('A'));
// 	printf("isascii: %d, ft_isascii: %d\n", isascii(127), ft_isascii(127));
// 	printf("isascii: %d, ft_isascii: %d\n", isascii(0), ft_isascii(0));
// 	printf("isascii: %d, ft_isascii: %d\n", isascii(128), ft_isascii(128));
// }
