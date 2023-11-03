/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_sleeping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:15:48 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/03 10:18:24 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_is_sleeping(t_philo *philo, t_routine *routine)
{
	if (routine->time_to_sleep == true)
	{
		//pthread_mutex_lock(&philo->table->time);
		print_save(SLEEP, philo);
		sleep_and_death_check(philo->table->time_to_sleep, philo);
		//pthread_mutex_unlock(&philo->table->time);
		routine->time_to_sleep = false;
		routine->time_to_think = true;
	}
}
