/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:27:33 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c))
		return (1);
	if (ft_isdigit(c))
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int	main()
// {
// 	printf("isalnum: %d, ft_isalnum: %d\n", isalnum('1'), ft_isalnum('1'));
// 	printf("isalnum: %d, ft_isalnum: %d\n", isalnum('A'), ft_isalnum('A'));
// 	printf("isalnum: %d, ft_isalnum: %d\n", isalnum('a'), ft_isalnum('a'));
// 	printf("isalnum: %d, ft_isalnum: %d\n", isalnum(' '), ft_isalnum(' '));
// 	printf("isalnum: %d, ft_isalnum: %d\n", isalnum('_'), ft_isalnum('_'));
// 	printf("isalnum: %d, ft_isalnum: %d\n", isalnum(0), ft_isalnum(0));
// }
