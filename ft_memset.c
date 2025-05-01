/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:39:57 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*s;

	s = buf;
	while (n > 0)
	{
		*s = ch;
		s++;
		n--;
	}
	return (buf);
}

// #include <string.h>
// #include <stdio.h>
// int	main()
// {
//     char str1[] = "0123456789";
//     char str2[] = "0123456789";

//     printf("memset: %s\n", (char *)memset(str1, '*', 5));
//     printf("ft_memset: %s\n", (char *)ft_memset(str2, '*', 5));

//     char *null_str1 = NULL;
//     char *null_str2 = NULL;

//     printf("memset with NULL: %p\n", memset(null_str1, '*', 5));
//     printf("ft_memset with NULL: %p\n", ft_memset(null_str2, '*', 5));

// 	return 0;
// }
