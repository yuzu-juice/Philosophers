/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:18:33 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/04 00:29:14 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORKS_H
# define FORKS_H
# include "philo.h"

void	take_forks(pthread_mutex_t *forks_mutex, int fork_id_1, int fork_id_2);
void	put_forks(pthread_mutex_t *forks_mutex, int fork_id_1, int fork_id_2);

#endif
