/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:54:58 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (!s1[i] || !s2[i])
			break ;
		if (s1[i] != s2[i])
			break ;
		if (s1[i] == s2[i] && i == n - 1)
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *s1 = "abcdefgh";
// 	char *s2 = "abcdwxyz";
// 	printf("strncmp: %d\n", strncmp(s1, s2, 5));
// 	printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, 5));

// 	s1 = "";
// 	s2 = "";
// 	printf("strncmp: %d\n", strncmp(s1, s2, 4));
// 	printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, 4));
// }
