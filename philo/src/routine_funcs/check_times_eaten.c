/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_times_eaten.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:00:40 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/04 10:56:21 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void			note_philo_ate(t_philo *philo);
static void			tell_table_a_meal_got_served(t_philo *philo);
static void			check_if_every_philo_ate_enough(t_philo *philo);
static void			stop_routine(t_philo *philo);

void	check_times_eaten(t_philo *philo)
{
	if (philo->table->time_each_philo_must_eat != -1)
	{
		note_philo_ate(philo);
		tell_table_a_meal_got_served(philo);
		check_if_every_philo_ate_enough(philo);
	}
}

static void	note_philo_ate(t_philo *philo)
{
	philo->times_eaten++;
}
static void	tell_table_a_meal_got_served(t_philo *philo)
{
	pthread_mutex_lock(&philo->protect_times_eaten);
	if (philo->times_eaten == philo->table->time_each_philo_must_eat)
		philo->table->dinner_served++;
	pthread_mutex_unlock(&philo->protect_times_eaten);
}

static void	check_if_every_philo_ate_enough(t_philo *philo)
{
	int	times_dinner_served;

	pthread_mutex_lock(&philo->table->protect_dinner_served);
	times_dinner_served = philo->table->dinner_served;
	pthread_mutex_unlock(&philo->table->protect_dinner_served);
	if (times_dinner_served == philo->table->time_each_philo_must_eat)
		stop_routine(philo);
}

static void	stop_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect_run_routine);
	philo->table->run_routine = false;
	pthread_mutex_unlock(&philo->table->protect_run_routine);
}
