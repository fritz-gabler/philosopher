/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_eating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:18:17 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/30 16:20:50 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_is_eating(t_philo *philo, t_routine *routine)
{
	if (routine->think == true || routine->eat == false)
		return ;
	sleep_and_death_check(philo->table->time_to_eat, philo);
	philo->last_time_eating = get_current_time_in_mill();
	routine->sleeps = true;
}
