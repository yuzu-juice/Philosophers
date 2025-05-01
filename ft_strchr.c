/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:51:46 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (1)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
}

// #include <stdio.h>
// #include <string.h>
// int	main(){
// 	const char s[] = "test string";
// 	int	c = 'a';
// 	printf("%p, %p\n", strchr(s, c), ft_strchr(s, c));

// 	const char s1[] = "";
// 	c = '\0';
// 	printf("%p, %p\n", strchr(s1, c), ft_strchr(s1, c));

// 	const char *s2 = NULL;
// 	c = '\0';
// 	printf("%p\n", strchr(s2, c));
// 	printf("%p\n", ft_strchr(s2, c));
// }
