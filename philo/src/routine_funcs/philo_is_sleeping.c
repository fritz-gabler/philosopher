/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_sleeping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:15:48 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/01 17:45:34 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	reset_routine(t_routine *routine);

void	philo_is_sleeping(t_philo *philo, t_routine *routine)
{
	if (routine->time_to_sleep == false)
		return ;
	pthread_mutex_lock(&philo->table->time);
	sleep_and_death_check(philo->table->time_to_sleep, philo);
	pthread_mutex_unlock(&philo->table->time);
	routine->time_to_sleep = false;
	routine->time_to_think = false;
	reset_routine(routine);
}

static void	reset_routine(t_routine *routine)
{
	routine->time_to_sleep = false;
	routine->time_to_eat = false;
	routine->time_to_look_for_fork = false;
	routine->time_to_think = true;
}
