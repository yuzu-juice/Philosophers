/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 01:13:36 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size == 0)
	{
		nmemb = 0;
		size = 1;
	}
	if (SIZE_MAX / size < nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main()
// {
// 	int	s = 3;
// 	int	*ptr1;
// 	int *ptr2;
// 	int *ptr3;
// 	int *ptr4;

// 	printf("calloc\n");
// 	ptr1 = calloc(s, sizeof(int));
// 	for (int i = 0; i < s; i++)
// 		printf("%d\n", ptr1[i]);

// 	printf("\nft_calloc\n");
// 	ptr2 = ft_calloc(3, sizeof(int));
// 	for (int i = 0; i < s; i++)
// 		printf("%d\n", ptr2[i]);
// 	ptr3 = calloc(1, 0);
// 	printf("%p\n", ptr3);
// 	ptr4 = ft_calloc(1, 0);
// 	printf("%p\n", ptr4);
// 	return (0);
// }
