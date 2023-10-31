/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_died.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:26:57 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/30 16:14:18 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_died(t_philo *philo)
{
	long long	last_time_eaten;

	last_time_eaten = get_current_time_in_mill() - philo->last_time_eating;
	if (last_time_eaten > philo->table->time_to_die)
	{
		pthread_mutex_lock(&philo->table->protect_all_alive);
		philo->table->all_philos_alive = false;
		pthread_mutex_unlock(&philo->table->protect_all_alive);
		return (true);
	}
	return (false);
}