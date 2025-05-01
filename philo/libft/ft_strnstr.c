/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:12:09 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	size_t	big_len;

	i = 0;
	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	if (little_len == 0)
		return ((char *)&big[i]);
	if (len == 0 || big_len < little_len || len < little_len)
		return (NULL);
	if (big_len < len)
		len = big_len;
	while (i < len - little_len + 1)
	{
		if (ft_strncmp(&big[i], little, little_len) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//     const char *big = "Hello, world!";
//     const char *little = "world";
//     size_t len = strlen(big);

//     // Test case 1: Little string is found in big string
//     printf("strnstr: %s\n", strnstr(big, little, len));
//     printf("ft_strnstr: %s\n", ft_strnstr(big, little, len));

//     // Test case 2: Little string is not found in big string
//     big = "Hello, world!";
//     little = "foo";
//     printf("strnstr: %s\n", strnstr(big, little, len));
//     printf("ft_strnstr: %s\n", ft_strnstr(big, little, len));

//     // Test case 3: Little string is empty
//     big = "Hello, world!";
//     little = "";
//     printf("strnstr: %s\n", strnstr(big, little, len));
//     printf("ft_strnstr: %s\n", ft_strnstr(big, little, len));

//     big = "";
//     little = "";
//     printf("strnstr: %s\n", strnstr(big, little, len));
//     printf("ft_strnstr: %s\n", ft_strnstr(big, little, len));

//     return 0;
// }
