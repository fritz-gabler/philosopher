/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_died.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:26:57 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/01 17:28:11 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_died(t_philo *philo)
{
	long long	last_time_eaten;

	pthread_mutex_lock(&philo->table->protect_run_routine);
	last_time_eaten = get_current_time_in_mill() - philo->last_time_eating;
	if (last_time_eaten > philo->table->time_to_die)
	{
		print_save(DIE, philo);
		philo->table->run_routine = false;
		pthread_mutex_unlock(&philo->table->protect_run_routine);
		return (true);
	}
	else
		pthread_mutex_unlock(&philo->table->protect_run_routine);
	return (false);
}
