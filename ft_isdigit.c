/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:27:33 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main()
// {
// 	printf("isdigit: %d, ft_isdigit: %d\n", isdigit('a'), ft_isdigit('a'));
// 	printf("isdigit: %d, ft_isdigit: %d\n", isdigit('A'), ft_isdigit('A'));
// 	printf("isdigit: %d, ft_isdigit: %d\n", isdigit('1'), ft_isdigit('1'));
// 	printf("isdigit: %d, ft_isdigit: %d\n", isdigit(0), ft_isdigit(0));
// }
