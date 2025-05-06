/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:20:14 by takitaga          #+#    #+#             */
/*   Updated: 2025/05/06 20:37:36 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_pthread_ptr_result	create_philo_threads(t_waiter *w);
static t_philo_result		init_philo(t_waiter *w, int philo_id);

t_error	philo(t_waiter w)
{
    t_pthread_ptr_result	result;
    pthread_t				watchdog_th;
    int						i;

    if (w.num_of_philos == 1)
    {
        printf("%d %d died\n", w.time_to_die, 0);
        return (create_success());
    }
    if (pthread_create(&watchdog_th, NULL, watchdog, &w) != 0)
        return (create_error(ERR_THREAD_CREATE));
    result = create_philo_threads(&w);
    if (result.error.is_error)
    {
        if (result.tid)
            ft_free(result.tid);
        if (result.args)
            ft_free(result.args);
        return (result.error);
    }
    i = 0;
    while (i < w.num_of_philos)
    {
        pthread_join(result.tid[i], NULL);
        i++;
    }
    pthread_join(watchdog_th, NULL);
    ft_free(result.tid);
    ft_free(result.args);
    return (create_success());
}

static t_pthread_ptr_result	create_philo_threads(t_waiter *w)
{
    t_pthread_ptr_result	result;
    t_philo_result			philo_result;
    t_philo					*philo_instance;
    int						i;

    result.error = create_success();
    result.tid = NULL;
    result.args = NULL;
    i = 0;

    result.tid = ft_calloc(w->num_of_philos, sizeof(pthread_t));
    if (result.tid == NULL)
    {
        result.error = create_error(ERR_MEMORY);
        return (result);
    }

    result.args = ft_calloc(w->num_of_philos, sizeof(t_thread_arg));
    if (result.args == NULL)
    {
        result.error = create_error(ERR_MEMORY);
        return (result);
    }

    while (i < w->num_of_philos)
    {
        philo_result = init_philo(w, i);
        if (philo_result.error.is_error)
        {
            result.error = philo_result.error;
            return (result);
        }
        philo_instance = philo_result.philo;
        w->philos[i] = *philo_instance;

        result.args[i].w = w;
        result.args[i].philo_id = i;

        if (pthread_create(&result.tid[i], NULL, philo_thread, &result.args[i]) != 0)
        {
            ft_free(philo_instance);
            result.error = create_error(ERR_THREAD_CREATE);
            return (result);
        }
        ft_free(philo_instance);
        i++;
    }
    return (result);
}

static t_philo_result	init_philo(t_waiter *w, int philo_id)
{
    t_philo_result	result;

    result.philo = ft_calloc(1, sizeof(t_philo));
    if (result.philo == NULL)
    {
        result.error = create_error(ERR_MEMORY);
        return (result);
    }
    result.error = create_success();
    result.philo->philo_id = philo_id;
    result.philo->l_fork_id = philo_id;
    result.philo->r_fork_id = (philo_id + 1) % w->num_of_philos;
    result.philo->eat_count = 0;
    result.philo->last_meal_time = timestamp();
    result.philo->is_dead = false;
    return (result);
}
