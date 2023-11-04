/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:08:05 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/04 13:37:29 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philo_content(t_philo *philo, t_table *table, int id);
static void	set_ptr_to_next_philo(t_philo *philo,
		unsigned int i, t_philo **save_philo);

void	create_philo_struct(t_philo **philo, t_table *table)
{
	t_philo			*create_philo;
	t_philo			*save_philo;
	unsigned int	i;

	i = 0;
	while (i < table->nbr_of_philo)
	{
		create_philo = (t_philo *) malloc(sizeof(t_philo));
		set_philo_content(create_philo, table, i);
		set_ptr_to_next_philo(create_philo, i, &save_philo);
		i++;
	}
	*philo = create_philo;
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
