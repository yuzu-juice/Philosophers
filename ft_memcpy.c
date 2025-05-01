/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:39:08 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	i = 0;
	if (n == 0 || (d == NULL && s == NULL))
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

// #include <string.h>
// #include <stdio.h>
// int	main()
// {
// 	char	str1[] = "0123456789";
// 	char	str2[] = "9876543210";
// 	char	str3[] = "9876543210";
// 	printf("memcpy: %s, ft_memcpy: %s\n", memcpy(str1, str2, 5), 
//			ft_memcpy(str1, str3, 5));

//  	char str4[] = "0123456789";
//     char str5[] = "";
//     char str6[] = "";
// 	printf("memcpy: %s, ft_memcpy: %s\n", memcpy(str4, str5, 5),
//		 ft_memcpy(str4, str6, 5));

//     char *null_str = NULL;
//     char *null_str1 = NULL;
//     char *null_str2 = NULL;
//     printf("memcpy: %s\n", memcpy(null_str, null_str1, 5));
// 	printf("ft_memcpy: %s\n", ft_memcpy(null_str, null_str2, 5));

//     return 0;
// }
