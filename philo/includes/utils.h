/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:57:45 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 07:31:58 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include "types.h"

int		ft_atouint(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_free(void *mem);
bool	should_stop(t_table *t);
void	set_stop_flag(t_table *t);
void	free_t_pthread_ptr(t_pthread_ptr_result *ptr);

#endif
