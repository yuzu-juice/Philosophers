/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:27:33 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main()
// {
// 	printf("isalpha: %d, ft_isalpha: %d\n", isalpha('a'), ft_isalpha('a'));
// 	printf("isalpha: %d, ft_isalpha: %d\n", isalpha('A'), ft_isalpha('A'));
// 	printf("isalpha: %d, ft_isalpha: %d\n", isalpha('1'), ft_isalpha('1'));
// 	printf("isalpha: %d, ft_isalpha: %d\n", isalpha(' '), ft_isalpha(' '));
// 	printf("isalpha: %d, ft_isalpha: %d\n", isalpha(0), ft_isalpha(0));
// }
