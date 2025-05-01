/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:39:55 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f((unsigned int)i, s[i]);
		i++;
	}
	return (str);
}

// #include <stdio.h>

// char ft_replace_with_star(unsigned int index, char c) {
// 	(void)index;
// 	c = '*';
// 	return (c);
// }

// int main()
// {
// 	char *s = "Hello";
// 	char *str = ft_strmapi(s, &ft_replace_with_star);
// 	printf("%s\n", str);
// 	return (0);
// }
