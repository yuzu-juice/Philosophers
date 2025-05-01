/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:20:48 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if (s_len < start + len)
		len = s_len - start;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s + start, len);
	ptr[len] = '\0';
	return (ptr);
}

// #include <stdio.h>
// int main()
// {
// 	char	*str = "Hello, World!";
// 	char	*ptr1 = ft_substr(str, 7, 5);
// 	char	*ptr2 = ft_substr(str, 0, 5);
// 	char	*ptr3 = ft_substr(str, 0, 13);
// 	char	*ptr4 = ft_substr(str, 0, 14);
// 	char	*ptr5 = ft_substr(str, 0, 15);
// 	char	*ptr6 = ft_substr(str, 20, 16);
// 	char	*ptr7 = ft_substr(NULL, 0, 2);
// 	printf("ft_substr: %s\n", ptr1);
// 	printf("ft_substr: %s\n", ptr2);
// 	printf("ft_substr: %s\n", ptr3);	
// 	printf("ft_substr: %s\n", ptr4);
// 	printf("ft_substr: %s\n", ptr5);
// 	printf("ft_substr: %s\n", ptr6);
// 	printf("ft_substr: %s\n", ptr7);
// 	return (0);
// }
