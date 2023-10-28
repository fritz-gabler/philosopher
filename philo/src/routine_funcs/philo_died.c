/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_died.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:26:57 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/28 13:48:47 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_died(t_philo *philo)
{
	long long	current_time;

	current_time = get_current_time_in_mill() - philo->table->start_of_dinner;
	if (current_time > philo->table->time_to_die)
	{
		philo->table->all_philos_alive = false;
		return (true);
	}
	return (false);
}
