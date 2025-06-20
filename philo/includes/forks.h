/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:18:33 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 07:36:27 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORKS_H
# define FORKS_H

# include "types.h"

t_error	take_forks(t_table *t, int fork_id_1, int fork_id_2);
void	put_forks(t_table *t, int fork_id_1, int fork_id_2);

#endif
