/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_thinking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:23:08 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/01 17:41:34 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	reset_routine(t_routine *routine);

void	philo_is_thinking(t_philo *philo, t_routine *routine)
{
	if (routine->time_to_think == true)
	{
		print_save(THINK, philo);
		reset_routine(routine);
	}
}

static void	reset_routine(t_routine *routine)
{
	routine->time_to_look_for_fork = true;
	routine->time_to_eat = false;
	routine->time_to_sleep = false;
	routine->time_to_think = false;
}
