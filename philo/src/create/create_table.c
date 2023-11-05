/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:41:40 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/05 15:43:45 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int		create_table_mutex(t_table *table);
static void		set_table_variables(t_table *table);
static void		set_input_to_table(t_input *input, t_table *table);

int	create_table(t_table **table, t_input *input)
{
	t_table			*tmp_table;

	tmp_table = malloc(sizeof(t_table));
	if (tmp_table == NULL)
		return (free(input), false);
	set_input_to_table(input, tmp_table);
	if (create_table_mutex(tmp_table) == false)
		return (free(tmp_table), free(input), false);
	set_table_variables(tmp_table);
	*table = tmp_table;
	free(input);
	return (true);
}

static void	set_input_to_table(t_input *input, t_table *table)
{
	table->nbr_of_philo = ft_atoi(input->av[1]);
	table->time_to_die = ft_atoi(input->av[2]);
	table->time_to_eat = ft_atoi(input->av[3]);
	table->time_to_sleep = ft_atoi(input->av[4]);
	if (input->ac == 6)
		table->time_each_philo_must_eat = ft_atoi(input->av[5]);
	else
		table->time_each_philo_must_eat = -1;
}

static void	set_table_variables(t_table *table)
{
	table->start_of_dinner = get_current_time_in_mill();
	table->run_routine = true;
	table->all_threads_created = false;
	table->threads_creation_failed = false;
	if (table->nbr_of_philo == 1)
		table->single_meal = true;
	else
		table->single_meal = false;
}

static int	create_table_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->protect_message, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&table->protect_run_routine, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&table->protect_dinner_served, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&table->protect_creation_failed, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&table->protect_all_threads_created, NULL) != 0)
		return (false);
	return (true);
}
