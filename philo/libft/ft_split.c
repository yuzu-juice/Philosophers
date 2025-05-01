/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:58:43 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static char		*get_until_c(char const *s, char c);
static void		*free_result(char **result, size_t result_i);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**result;
	size_t	result_i;

	i = 0;
	result_i = 0;
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result || !s)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		result[result_i] = get_until_c(&s[i], c);
		if (result[result_i] == NULL)
			return (free_result(result, result_i));
		i += ft_strlen(result[result_i]);
		result_i++;
	}
	result[result_i] = NULL;
	return (result);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		flag;

	i = 0;
	count = 0;
	flag = 1;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		if (flag && s[i] != c)
		{
			count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

static char	*get_until_c(char const *s, char c)
{
	size_t		i;
	char const	*tmp;

	i = 0;
	tmp = &s[i];
	while (1)
	{
		if (s[i] == c || s[i] == '\0')
			break ;
		i++;
	}
	return (ft_substr(tmp, 0, i));
}

static void	*free_result(char **result, size_t result_i)
{
	while (result_i > 0)
	{
		free(result[result_i - 1]);
		result_i--;
	}
	free(result);
	return (NULL);
}

// #include <stdio.h>

// int main(void) {
//     size_t i;
//     char **test;
//     const char *test_cases[] = {
//         "Hello world this is a test",
//         "Another,test,with,commas",
//         "   Spaces   everywhere  ",
//         "SingleWord",
//         "    ",
//         "",
//         NULL // 終端
//     };

//     for (size_t j = 0; test_cases[j] != NULL; j++) {
//         printf("Test case %zu: \"%s\"\n", j + 1, test_cases[j]);
//         test = ft_split(test_cases[j], ' '); // スペースで区切り
//         if (test) {
//             for (i = 0; test[i]; i++) {
//                 printf("%zu: %s\n", i, test[i]);
//                 free(test[i]);
//             }
//             free(test);
//         } else {
//             printf("Memory allocation failed\n");
//         }
//         printf("\n");
//     }

// 	printf("NULL input test case:\n");
//     test = ft_split(NULL, ' ');
//     if (test == NULL) {
//         printf("NULL input correctly handled.\n");
//     } else {
//         printf("NULL input test failed.\n");
//     }

//     return 0;
// }
