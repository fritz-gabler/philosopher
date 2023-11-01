/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_free_forks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:58:36 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/01 11:12:13 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_forks_are_in_use(t_philo *philo);

void	check_for_free_forks(t_philo *philo, t_routine *routine)
{
	if (routine->time_to_look_for_fork == false)
		return ;
	pthread_mutex_lock(&philo->protect_fork);
	pthread_mutex_lock(&philo->next_philo->protect_fork);
	if (philo->fork == FORK_IS_FREE
			&& philo->next_philo->fork == FORK_IS_FREE)
	{
		set_forks_are_in_use(philo);
		print_save(FORK, philo);
		print_save(FORK, philo);
		routine->time_to_look_for_fork = false;
		routine->time_to_eat = true;
	}
	pthread_mutex_unlock(&philo->next_philo->protect_fork);
	pthread_mutex_unlock(&philo->protect_fork);
}

static void	set_forks_are_in_use(t_philo *philo)
{
	philo->fork = FORK_IN_USE;
	philo->next_philo->fork = FORK_IN_USE;
}
