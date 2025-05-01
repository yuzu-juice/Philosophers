/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 01:19:46 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	s_len;

	s_len = ft_strlen(s);
	ptr = (char *)malloc(s_len + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, s_len);
	ptr[s_len] = '\0';
	return (ptr);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char	*str = "Hello, World!";
// 	printf("ft_strdup: %s\n", ft_strdup(str));
// 	printf("strdup: %s\n", strdup(str));

// 	char	*str1 = "";
// 	printf("ft_strdup: %s\n", ft_strdup(str1));
// 	printf("strdup: %s\n", strdup(str1));

// 	char	*str2 = NULL;
// 	printf("ft_strdup: %s\n", ft_strdup(str2));
// 	printf("strdup: %s\n", strdup(str2));

// 	return (0);
// }
