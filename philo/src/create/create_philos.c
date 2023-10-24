/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:43:34 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/24 19:04:32 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philo_content(t_philo *philo, t_table *table, int id);
static void	create_thread(t_philo *philo, int i);
static void	set_ptr_to_next_philo(t_philo *philo, int i, t_philo *save_philo);

int	create_philo (t_philo **philo, t_table *table)
{
	t_philo			*create_philo;
	t_philo			*save_philo;
	int				i;

	i = 0;
	while (i < table->nbr_of_philo)
	{
		set_philo_content(create_philo, table, i);
		create_thread(create_philo, i);
		set_ptr_to_next_philo(create_philo, i ,save_philo);
		i++;
	}
	return (true);
}

static void	set_philo_content(t_philo *philo, t_table *table, int id)
{
	create_mutex(&philo->protect_fork);
	philo->table = table;
	philo->times_eaten = 0;
	philo->fork = FORK_IS_FREE;
	philo->started_eating = get_current_time_in_mill();
	philo->id = id;
}

static void	create_thread(t_philo *philo, int i)
{
	philo->table->thread_ids[i] =
		pthread_create(philo->philo, NULL, &routine, NULL);
}

static void	set_ptr_to_next_philo(t_philo *philo, int i, t_philo *save_philo)
{
	if (i == 0)
	{
		philo->table->first_philo = (void *) philo;
		save_philo = philo;
	}
	else if (i == philo->table->nbr_of_philo)
	{
		philo->next_philo = philo->table->first_philo;
	}
	else
	{
		save_philo->next_philo = philo;
		save_philo = philo;
	}
}
