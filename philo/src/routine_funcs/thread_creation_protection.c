/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation_protection.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:59:30 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/07 11:17:46 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_creation_failed(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect_creation_failed);
	philo->table->threads_creation_failed = true;
	pthread_mutex_unlock(&philo->table->protect_creation_failed);
}

void	set_all_threads_created(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect_all_threads_created);
	philo->table->all_threads_created = true;
	pthread_mutex_unlock(&philo->table->protect_all_threads_created);
	pthread_mutex_lock(&philo->table->protect_start_time);
	philo->table->start_of_dinner = get_current_time_in_mill();
	pthread_mutex_unlock(&philo->table->protect_start_time);
}

int	check_all_threads_created(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect_all_threads_created);
	if (philo->table->all_threads_created == true)
	{
		pthread_mutex_unlock(&philo->table->protect_all_threads_created);
		return (true);
	}
	pthread_mutex_unlock(&philo->table->protect_all_threads_created);
	return (false);
}

int	threads_creation_failed(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect_creation_failed);
	if (philo->table->threads_creation_failed == true)
	{
		pthread_mutex_unlock(&philo->table->protect_creation_failed);
		return (true);
	}
	pthread_mutex_unlock(&philo->table->protect_creation_failed);
	return (false);
}
