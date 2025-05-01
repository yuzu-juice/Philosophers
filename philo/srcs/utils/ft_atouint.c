/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atouint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:59:50 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/02 02:11:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	ft_atoi(const char *nptr);
static int	check_overflow(int sign, long l, char next);
static int	ft_isspace(const char c);
static int	ft_isnum(char *s);

int	ft_atouint(char *str)
{
	int		result;

	if (!ft_isnum(str))
		return (-1);
	result = ft_atoi(str);
	if (result < 0)
		return (-1);
	return (result);
}

static int	ft_atoi(const char *nptr)
{
	long	ret_value;
	int		sign;
	size_t	i;

	ret_value = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			break ;
		if (check_overflow(sign, ret_value, nptr[i]) != 0)
			return (-1);
		ret_value = ret_value * 10 + (long)(nptr[i] - '0');
		i++;
	}
	if (sign * ret_value > INT_MAX || sign * ret_value < INT_MIN)
		return (-1);
	return ((int)(sign * ret_value));
}

static int	check_overflow(int sign, long l, char next)
{
	if (sign == 1)
		if (LONG_MAX / 10 < l
			|| (LONG_MAX / 10 == l && LONG_MAX % 10 < next - '0'))
			return (1);
	if (sign == -1)
		if (LONG_MIN / -10 < l
			|| (LONG_MIN / -10 == l && LONG_MIN % -10 * -1 < next - '0'))
			return (-1);
	return (0);
}

static int	ft_isspace(const char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	ft_isnum(char *s)
{
	if (!s)
		return (false);
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '\0')
		return (false);
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (false);
		s++;
	}
	return (true);
}
