/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:35:10 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/14 13:14:34 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	formats(va_list *ap, const char fmt)
{
	char	*s;

	if (fmt == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (fmt == 's')
	{
		s = va_arg(*ap, char *);
		if (!s)
			s = "(null)";
		return (ft_putstr(s));
	}
	else if (fmt == 'p')
		return (ft_putptr((uintptr_t)va_arg(*ap, void *)));
	else if (fmt == 'd' || fmt == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (fmt == 'u')
		return (ft_putnbr_ui(va_arg(*ap, unsigned int)));
	else if (fmt == 'x')
		return (ft_puthex(va_arg(*ap, int), TRUE));
	else if (fmt == 'X')
		return (ft_puthex(va_arg(*ap, int), FALSE));
	else if (fmt == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	ssize_t	result;
	size_t	len;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			result = formats(&ap, *++fmt);
		else
			result = ft_putchar(*fmt);
		if (result < 0)
			return (result);
		len += result;
		fmt++;
	}
	va_end(ap);
	return (len);
}

int	ft_fprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	ssize_t	result;
	size_t	len;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			result = formats(&ap, *++fmt);
		else
		{
			ft_putchar_fd(*fmt, fd);
			result++;
		}
		if (result < 0)
			return (result);
		len += result;
		fmt++;
	}
	va_end(ap);
	return (len);
}

int	ft_println(const char *fmt, ...)
{
	va_list	ap;
	ssize_t	result;
	size_t	len;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			result = formats(&ap, *++fmt);
		else
			result = ft_putchar(*fmt);
		if (result < 0)
			return (result);
		len += result;
		fmt++;
	}
	va_end(ap);
	ft_printf("\n");
	return (len);
}

