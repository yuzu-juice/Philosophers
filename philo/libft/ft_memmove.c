/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:46:16 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	i = 0;
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	return (dst);
}

// #include <string.h>
// #include <stdio.h>
// int	main()
// {
// 	char	str1[] = "0123456789";
// 	char	str2[] = "0123456789";
//     printf("memmove: %s\n", memmove(str1, str1 + 3, 5));
//     printf("ft_memmove: %s\n", ft_memmove(str2, str2 + 3, 5));

//     char empty_str1[] = "";
//     char empty_str2[] = "";
//     printf("memmove with empty string: %s\n",
//				memmove(empty_str1, empty_str1, 0));
//     printf("ft_memmove with empty string: %s\n",
//				ft_memmove(empty_str2, empty_str2, 0));

//     char *null_str1 = NULL;
//     char *null_str2 = NULL;
//     printf("memmove with NULL: %p\n",
//				memmove(null_str1, null_str1, 5));
//     printf("ft_memmove with NULL: %p\n",
//				ft_memmove(null_str2, null_str2, 5));
// }
