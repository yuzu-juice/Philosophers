/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 02:01:06 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/05 17:56:38 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	ft_bzero(void *s, size_t n);

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

void	ft_free(void *mem)
{
	free(mem);
	mem = NULL;
}

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s1;

	s1 = s;
	while (n > 0)
	{
		*s1 = '\0';
		s1++;
		n--;
	}
}
