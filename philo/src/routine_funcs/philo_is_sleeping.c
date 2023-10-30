/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_sleeping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:15:48 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/30 16:26:16 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	reset_routine(t_routine *routine);

void	philo_is_sleeping(t_philo * philo, t_routine *routine)
{
	if (routine->sleeps == true)
	{
		sleep_and_death_check(philo->table->time_to_sleep, philo);
		reset_routine(routine);
	}
}

static void	reset_routine(t_routine *routine)
{
	routine->sleeps = false;
	routine->eat = false;
	routine->think = true;
}
