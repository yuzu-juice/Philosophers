/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:45:05 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 08:18:01 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_error	parse_args_and_validate(t_table *t, int argc, char **argv);
static t_error	init_resources(t_table *t);

t_table_result	init_table(int argc, char **argv)
{
	t_table_result	result;
	t_table			*t;

	t = &result.t;
	t->philos = NULL;
	t->forks = NULL;
	t->forks_mutex = NULL;
	result.error = create_success();
	result.error = parse_args_and_validate(t, argc, argv);
	if (result.error.is_error)
		return (result);
	t->philos = ft_calloc(t->num_of_philos, sizeof(t_philo));
	if (t->philos == NULL)
	{
		result.error = create_error(ERR_MEMORY);
		return (result);
	}
	result.error = init_resources(t);
	return (result);
}

void	cleanup_table(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->num_of_forks)
	{
		pthread_mutex_destroy(&t->forks_mutex[i]);
		i++;
	}
	i = 0;
	while (i < t->num_of_philos)
	{
		pthread_mutex_destroy(&t->philos[i].philo_mutex);
		i++;
	}
	pthread_mutex_destroy(&t->print_mutex);
	pthread_mutex_destroy(&t->stop_mutex);
	ft_free(t->philos);
	ft_free(t->forks);
	ft_free(t->forks_mutex);
}

static t_error	parse_args_and_validate(t_table *t, int argc, char **argv)
{
	t->start_time = timestamp();
	t->num_of_philos = ft_atouint(argv[1]);
	t->num_of_forks = t->num_of_philos;
	t->time_to_die = ft_atouint(argv[2]);
	t->time_to_eat = ft_atouint(argv[3]);
	t->time_to_sleep = ft_atouint(argv[4]);
	if (argc == 6)
		t->num_of_times_each_philo_must_eat = ft_atouint(argv[5]);
	else
		t->num_of_times_each_philo_must_eat = INT_MAX;
	if (t->num_of_philos <= 0 || t->num_of_philos >= 1000 || t->time_to_die <= 0
		|| t->time_to_eat <= 0 || t->time_to_sleep <= 0
		|| (argc == 6 && t->num_of_times_each_philo_must_eat <= 0))
		return (create_error(ERR_INVALID_ARGS));
	return (create_success());
}

static t_error	init_resources(t_table *t)
{
	t_error	error;

	error = init_forks(t);
	if (error.is_error)
		return (error);
	if (pthread_mutex_init(&t->print_mutex, NULL) != 0)
		return (create_error(ERR_MUTEX_INIT));
	if (pthread_mutex_init(&t->stop_mutex, NULL) != 0)
		return (create_error(ERR_MUTEX_INIT));
	t->should_stop = false;
	return (error);
}
