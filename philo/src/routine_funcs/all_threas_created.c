/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_threas_created.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:24:13 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/07 11:33:57 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_for_odd(t_philo *philo);
static int	odd_philo_nbr(t_philo *philo);
static int	all_add_philos_started(t_philo *philo);

int	all_threads_created(t_philo *philo)
{
	while (check_all_threads_created(philo) == false)
	{
		if (threads_creation_failed(philo) == true)
		{
			return (false);
		}
		usleep(50);
	}
	wait_for_odd(philo);
	return (true);
}

static void	wait_for_odd(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->table->protect_all_add_started);
		philo->table->all_add_started++;
		pthread_mutex_unlock(&philo->table->protect_all_add_started);
		return ;
	}
	while (all_add_philos_started(philo) == false)
	{
		usleep(100);
	}
}

static int	all_add_philos_started(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect_all_add_started);
	if (philo->table->all_add_started >= odd_philo_nbr(philo))
	{
		pthread_mutex_unlock(&philo->table->protect_all_add_started);
		return (true);
	}
	pthread_mutex_unlock(&philo->table->protect_all_add_started);
	return (false);
}

static int	odd_philo_nbr(t_philo *philo)
{
	return ((int)(philo->table->nbr_of_philo / 2)
			+ philo->table->nbr_of_philo % 2);
}
