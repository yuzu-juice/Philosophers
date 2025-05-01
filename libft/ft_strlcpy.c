/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:24:30 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (s[i] && i < dstsize - 1)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strncpy(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize)
	{
		d[i] = s[i];
		i++;
	}
	return (ft_strlen(src));
}

// #include <string.h>
// #include <stdio.h>
// int	main()
// {
// 	char	str1[] = "01234";
// 	char	str2[] = "01234";
// 	char	str_src[] = "9876543210";

// 	strlcpy(str1, str_src, sizeof(str1));
// 	ft_strlcpy(str2, str_src, sizeof(str2));
// 	printf("%s, %s\n", str1, str2);
// }
