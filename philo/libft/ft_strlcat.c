/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:49:28 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		dst_len;
	size_t		src_len;
	size_t		i;

	d = dst;
	s = src;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (s[i] && (dst_len + i) < (dstsize - 1))
	{
		d[dst_len + i] = s[i];
		i++;
	}
	d[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// #include <string.h>
// #include <stdio.h>
// int main() {
// 	char dest1[9] = "Hello";
// 	const char *src1 = " World";

// 	printf("strlcat\n");
// 	printf("Before: %s\n", dest1);
// 	size_t result1 = strlcat(dest1, src1, sizeof(dest1));
// 	printf("After: %s\n", dest1);
// 	printf("Total length: %zu\n\n", result1);

// 	char dest2[9] = "Hello";
// 	const char *src2 = " World";

// 	printf("ft_strlcat\n");
// 	printf("Before: %s\n", dest2);
// 	size_t result2 = ft_strlcat(dest2, src2, sizeof(dest2));
// 	printf("After: %s\n", dest2);
// 	printf("Total length: %zu\n", result2);
// }
