/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_eating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:18:17 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/07 13:19:08 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	update_last_time_eating(t_philo *philo);
static void	set_fork_to_available(t_philo *philo);
static void	put_down_right_fork(t_philo *philo);
static void	put_down_left_fork(t_philo *philo);

void	philo_is_eating(t_philo *philo, t_routine *routine)
{
	if (routine->time_to_eat == true)
	{
		print_save(EAT, philo);
		sleep_and_death_check(philo->table->time_to_eat, philo);
		set_fork_to_available(philo);
		check_times_eaten(philo);
		update_last_time_eating(philo);
		routine->time_to_eat = false;
		routine->time_to_sleep = true;
	}
}

static void	update_last_time_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->protect_times_eaten);
	philo->last_time_eating = get_current_time_in_mill();
	pthread_mutex_unlock(&philo->protect_times_eaten);
}

static void	set_fork_to_available(t_philo *philo)
{
	if (philo->id % 2)
	{
		put_down_left_fork(philo);
		put_down_right_fork(philo);
	}
	else
	{
		put_down_right_fork(philo);
		put_down_left_fork(philo);
	}
}

static void	put_down_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->protect_fork);
	philo->fork = FORK_IS_FREE;
	pthread_mutex_unlock(&philo->protect_fork);
}

static void	put_down_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->next_philo->protect_fork);
	philo->next_philo->fork = FORK_IS_FREE;
	pthread_mutex_unlock(&philo->next_philo->protect_fork);
}
