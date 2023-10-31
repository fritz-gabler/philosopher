/*/ ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:43:34 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/31 15:42:22 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_ptr_to_next_philo(t_philo *philo,
				unsigned int i, t_philo **save_philo);
static void	create_thread(t_philo *philo);
static void	set_philo_content(t_philo *philo, t_table *table, int id);

int	create_philo(t_philo **philo, t_table *table)
{
	t_philo			*create_philo;
	t_philo			*save_philo;
	unsigned int	i;

	i = 0;
	create_philo = NULL;
	save_philo = NULL;
	while (i < table->nbr_of_philo)
	{
		create_philo = (t_philo *) malloc(sizeof(t_philo));
		set_philo_content(create_philo, table, i);
		set_ptr_to_next_philo(create_philo, i, &save_philo);
		i++;
	}
	i = 0;
	while (i < table->nbr_of_philo)
	{
		create_thread(create_philo);
		create_philo = create_philo->next_philo;
		i++;
	}
	*philo = table->first_philo;
	return (true);
}

static void	set_philo_content(t_philo *philo, t_table *table, int id)
{
	create_mutex(&philo->protect_fork);
	philo->table = table;
	philo->times_eaten = 0;
	philo->fork = FORK_IS_FREE;
	philo->last_time_eating = get_current_time_in_mill();
	philo->id = id;
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

static void	create_thread(t_philo *philo)
{
	philo->philo = (pthread_t *) malloc (sizeof(pthread_t));
	pthread_create(philo->philo, NULL, &routine, philo);
}

