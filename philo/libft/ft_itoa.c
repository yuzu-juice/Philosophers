/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:39:55 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digits(int n);

char	*ft_itoa(int n)
{
	char	*str;
	size_t	digits;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digits = get_digits(n);
	if (n < 0)
	{
		digits++;
		n *= -1;
	}
	str = (char *)ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (digits-- > 0)
	{
		str[digits] = n % 10 + '0';
		n /= 10;
	}
	if (str[0] == '0')
		str[0] = '-';
	return (str);
}

static size_t	get_digits(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// 	int n = 2147483647;
// 	char *ptr1 = ft_itoa(n);
// 	printf("ft_itoa: %s\n", ptr1);
// 	free(ptr1);

// 	n = -2147483648;
// 	char *ptr2 = ft_itoa(n);
// 	printf("ft_itoa: %s\n", ptr2);
// 	free(ptr2);

// 	n = 0;
// 	char *ptr3 = ft_itoa(n);
// 	printf("ft_itoa: %s\n", ptr3);
// 	free(ptr3);

// 	n = -42;
// 	char *ptr4 = ft_itoa(n);
// 	printf("ft_itoa: %s\n", ptr4);
// 	free(ptr4);

// 	n = 42;
// 	char *ptr5 = ft_itoa(n);
// 	printf("ft_itoa: %s\n", ptr5);
// 	free(ptr5);

// 	return (0);
// }
