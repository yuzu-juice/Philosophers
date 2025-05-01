/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:27:15 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = s1;
	p2 = s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char str1[] = "Hello";
//     char str2[] = "Hello";
//     printf("memcmp: %d\n", memcmp(str1, str2, sizeof(str1)));
//     printf("ft_memcmp: %d\n", ft_memcmp(str1, str2, sizeof(str1)));

//     char str3[] = "Hello";
//     char str4[] = "World";
//     printf("memcmp: %d\n", memcmp(str3, str4, sizeof(str3)));
//     printf("ft_memcmp: %d\n", ft_memcmp(str3, str4, sizeof(str3)));

//     char str5[] = "Hello";
//     char str6[] = "Hella";
//     printf("memcmp: %d\n", memcmp(str5, str6, sizeof(str5)));
//     printf("ft_memcmp: %d\n", ft_memcmp(str5, str6, sizeof(str5)));

//     char str7[] = "";
//     char str8[] = "";
//     printf("memcmp: %d\n", memcmp(str7, str8, sizeof(str7)));
//     printf("ft_memcmp: %d\n", ft_memcmp(str7, str8, sizeof(str7)));

//     printf("memcmp: %d\n", memcmp(NULL, NULL, 1));
//     printf("ft_memcmp: %d\n", ft_memcmp(NULL, NULL, 1));
//     return 0;
// }
