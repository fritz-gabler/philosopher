/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_died.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:26:57 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/06 13:05:39 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_last_time_eaten(long long *last_time_eaten, t_philo *philo);
static void	stop_routine(t_philo *philo);
static void	announce_deth(t_philo *philo);

int	philo_died(t_philo *philo)
{
	long long	last_time_eaten;

	get_last_time_eaten(&last_time_eaten, philo);
	if ((last_time_eaten > philo->table->time_to_die))
	{
		pthread_mutex_lock(&philo->table->protect_message);
		announce_deth(philo);
		stop_routine(philo);
		pthread_mutex_unlock(&philo->table->protect_message);
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
	philo->table->run_routine = false;
}

static void	announce_deth(t_philo *philo)
{
	long long	current_time;
	int			routine;

	routine = true;
	pthread_mutex_lock(&philo->table->protect_run_routine);
	if (philo->table->run_routine == false)
		routine = false;
	pthread_mutex_unlock(&philo->table->protect_run_routine);
	current_time = get_current_time_in_mill() - philo->table->start_of_dinner;
	if (routine == true)
	{
		printf("%llu %d %s\n", current_time, philo->id, DIE);
	}
}
