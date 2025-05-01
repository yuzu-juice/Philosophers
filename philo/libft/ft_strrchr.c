/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:46:20 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	*ret_val;

	i = 0;
	str = (char *)s;
	ret_val = NULL;
	while (1)
	{
		if (str[i] == (char)c)
			ret_val = &str[i];
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (ret_val);
}

// #include <stdio.h>
// #include <string.h>
// int	main(){
// 	const char s[] = "test string";
// 	int	c = 't';
// 	printf("%p, %p\n", strrchr(s, c), ft_strrchr(s, c));
// }
