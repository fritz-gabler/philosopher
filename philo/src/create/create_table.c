/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:41:40 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/01 17:23:21 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		set_run_routine(t_table *table);
static void		set_input_to_table(t_input *input, t_table *table);
static void		get_dinner_start_time(t_table *table);
//static int		allocate_thread_ids(t_table *table);

int	create_table(t_table **table, t_input *input)
{
	t_table			*tmp_table;

	tmp_table = malloc(sizeof(t_table));
	if (tmp_table == NULL)
		return (false);
	set_run_routine(tmp_table);
	set_input_to_table(input, tmp_table);
	create_mutex(&tmp_table->protect_message);
	create_mutex(&tmp_table->protect_run_routine);
	create_mutex(&tmp_table->time);
	get_dinner_start_time(tmp_table);
//	if (allocate_thread_ids(tmp_table) == false)
//		return (free(tmp_table), false);
	*table = tmp_table;
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

static void	get_dinner_start_time(t_table *table)
{
	table->start_of_dinner = get_current_time_in_mill();
}

/*
static int	allocate_thread_ids(t_table *table)
{
	table->thread_ids = (int *) malloc((sizeof(int)) * (table->nbr_of_philo));
	if (table->thread_ids == NULL)
		return (false);
	return (true);
}
*/

static void	set_run_routine(t_table *table)
{
	table->run_routine = true;
}
