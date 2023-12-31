/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:08:05 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/06 13:41:31 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_one_philo(t_philo **philo, t_table *table);
static void	set_philo_content(t_philo *philo, t_table *table, int id);
static void	set_ptr_to_next_philo(t_philo *philo,
				unsigned int i, t_philo **save_philo);

int	create_philo_struct(t_philo **philo, t_table *table)
{
	t_philo			*create_philo;
	t_philo			*save_philo;
	unsigned int	i;

	i = 0;
	if (set_one_philo(philo, table) == true)
		return (true);
	while (i < table->nbr_of_philo)
	{
		create_philo = (t_philo *) malloc(sizeof(t_philo));
		if (create_philo == NULL)
			return (clear_structs(philo, &table, i), false);
		set_philo_content(create_philo, table, i);
		set_ptr_to_next_philo(create_philo, i, &save_philo);
		i++;
	}
	*philo = create_philo;
	return (true);
}

static void	set_philo_content(t_philo *philo, t_table *table, int id)
{
	pthread_mutex_init(&philo->protect_fork, NULL);
	pthread_mutex_init(&philo->protect_times_eaten, NULL);
	philo->table = table;
	philo->times_eaten = 0;
	philo->fork = FORK_IS_FREE;
	philo->last_time_eating = get_current_time_in_mill();
	philo->id = id + 1;
}

static void	set_ptr_to_next_philo(t_philo *philo,
		unsigned int i, t_philo **save_philo)
{
	if (i == 0)
	{
		philo->table->first_philo = (void *) philo;
		*save_philo = philo;
	}
	else if (i == (philo->table->nbr_of_philo - 1))
	{
		philo->next_philo = philo->table->first_philo;
		(*save_philo)->next_philo = philo;
	}
	else
	{
		(*save_philo)->next_philo = philo;
		*save_philo = philo;
	}
}

static int	set_one_philo(t_philo **philo, t_table *table)
{
	if (table->single_meal == true)
	{
		*philo = (t_philo *) malloc(sizeof(t_philo));
		if (philo == NULL)
			return (clear_structs(philo, &table, 0), false);
		set_philo_content(*philo, table, 0);
		(*philo)->next_philo = NULL;
	}
	return (false);
}
