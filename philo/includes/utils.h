/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:57:45 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/03 20:20:39 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_atouint(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
bool	check_someone_died(t_waiter *w);

#endif
