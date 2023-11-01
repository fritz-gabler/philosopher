/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_thinking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:23:08 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/01 11:10:22 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_is_thinking(t_philo *philo, t_routine *routine)
{
	if (routine->time_to_think == true)
	{
		print_save(THINK, philo);
		routine->time_to_think = false;
		routine->time_to_look_for_fork = true;
	}
}
