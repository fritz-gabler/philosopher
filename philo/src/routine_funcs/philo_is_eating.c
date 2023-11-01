/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_eating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:18:17 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/01 11:13:46 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_is_eating(t_philo *philo, t_routine *routine)
{
	if (routine->time_to_eat == false)
		return ;
	print_save(EAT, philo);
	sleep_and_death_check(philo->table->time_to_eat, philo);
	philo->last_time_eating = get_current_time_in_mill();
	routine->time_to_eat = false;
	routine->time_to_sleep = true;
}
