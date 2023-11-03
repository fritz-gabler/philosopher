/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_eating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:18:17 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/03 18:27:42 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_fork_to_available(t_philo *philo);

void	philo_is_eating(t_philo *philo, t_routine *routine)
{
	if (routine->time_to_eat == true)
	{
		print_save(EAT, philo);
		sleep_and_death_check(philo->table->time_to_eat, philo);
		//pthread_mutex_lock(&philo->);
		philo->last_time_eating = get_current_time_in_mill();
		//pthread_mutex_unlock(&philo->table->time);
		set_fork_to_available(philo);
		routine->time_to_eat = false;
		routine->time_to_sleep = true;
	}
}

static void	set_fork_to_available(t_philo *philo)
{
	pthread_mutex_lock(&philo->protect_fork);
	philo->fork = FORK_IS_FREE;
	philo->next_philo->fork = FORK_IS_FREE;
	pthread_mutex_unlock(&philo->protect_fork);
}
