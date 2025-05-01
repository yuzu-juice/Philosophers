/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:14:09 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char const c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;

	if (!s1)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	while (s1[i])
	{
		if (check_set(s1[i], set))
			i++;
		else
			break ;
	}
	j = 0;
	while (j < s1_len - i)
	{
		if (check_set(s1[s1_len - 1 - j], set))
			j++;
		else
			break ;
	}
	return (ft_substr(s1, i, s1_len - i - j));
}

static int	check_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     char *str1 = "Hello, World!";
//     char *set1 = "He!";
//     char *ptr1 = ft_strtrim(str1, set1);
//     printf("ft_strtrim: %s\n", ptr1);
//     free(ptr1);

//     // 空文字列のテストケース
//     char *str2 = "";
//     char *set2 = "He!";
//     char *ptr2 = ft_strtrim(str2, set2);
//     printf("ft_strtrim (empty string): %s\n", ptr2);
//     free(ptr2);

//     // NULLのテストケース
//     char *ptr3 = ft_strtrim(NULL, set1);
//     printf("ft_strtrim (NULL string): %s\n", ptr3);

//     char *ptr4 = ft_strtrim(str1, NULL);
//     printf("ft_strtrim (NULL set): %s\n", ptr4);

//     return 0;
// }
