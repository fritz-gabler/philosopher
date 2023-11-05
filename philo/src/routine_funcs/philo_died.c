/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_died.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:26:57 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/05 16:42:18 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_last_time_eaten(long long *last_time_eaten, t_philo *philo);
static void	stop_routine(t_philo *philo);

int	philo_died(t_philo *philo)
{
	long long	last_time_eaten;

	get_last_time_eaten(&last_time_eaten, philo);
	if (last_time_eaten > philo->table->time_to_die)
	{
		print_save(DIE, philo);
		stop_routine(philo);
		return (true);
	}
	return (false);
}

static void	get_last_time_eaten(long long *last_time_eaten, t_philo *philo)
{
	pthread_mutex_lock(&philo->protect_times_eaten);
	*last_time_eaten = get_current_time_in_mill() - philo->last_time_eating;
	pthread_mutex_unlock(&philo->protect_times_eaten);
}

static void	stop_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect_run_routine);
	philo->table->run_routine = false;
	pthread_mutex_unlock(&philo->table->protect_run_routine);
}
