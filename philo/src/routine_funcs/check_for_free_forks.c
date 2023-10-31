/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_free_forks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:58:36 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/31 15:48:08 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_forks_are_in_use(t_philo *philo);

void	check_for_free_forks(t_philo *philo, t_routine *routine)
{
	if (routine->think == false && routine->eat == false)
	{
		pthread_mutex_lock(&philo->protect_fork);
		pthread_mutex_lock(&philo->next_philo->protect_fork);
		if (philo->fork == FORK_IS_FREE &&
				philo->next_philo->fork == FORK_IS_FREE)
	{
			set_forks_are_in_use(philo);
			print_save(FORK, philo);
			print_save(FORK, philo->next_philo);
			routine->eat = true;
		}
		pthread_mutex_unlock(&philo->next_philo->protect_fork);
		pthread_mutex_unlock(&philo->protect_fork);
	}
}

static void	set_forks_are_in_use(t_philo *philo)
{
	philo->fork = FORK_IN_USE;
	philo->next_philo->fork = FORK_IN_USE;
}
