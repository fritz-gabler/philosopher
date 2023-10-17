/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:41:40 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/17 20:01:10 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_forks (t_table *table);

int	create_table(t_table **table, t_input *input)
{
	struct timeval	start_time;
	t_table			*tmp_table;

	tmp_table = malloc(sizeof(t_table));
	if (tmp_table == NULL)
		return (free(input), false);
	tmp_table->nbr_of_philos = ft_atoi(input->av[1]);
	if (create_forks(tmp_table) == false)
		return (free(input), free(tmp_table), false);
	tmp_table->time_to_die = ft_atoi(input->av[2]);
	tmp_table->time_to_eat = ft_atoi(input->av[3]);
	tmp_table->time_to_sleep = ft_atoi(input->av[4]);
	pthread_mutex_init(&tmp_table->print_save, NULL);
	(*table) = tmp_table;
	return (true);
}

static int	create_forks (t_table *table)
{
	int		i;

	i = 0;
	table->fork = malloc(sizeof(pthread_mutex_t) * (table->nbr_of_philos));
	if (table->fork == NULL)
		return (false);
	while (i < table->nbr_of_philos)
		pthread_mutex_init(&table->fork[i++], NULL);
	return (true);
}

