/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_free_forks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:58:36 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/05 18:54:17 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_forks_are_in_use(t_philo *philo);
static int	left_and_right_fork_is_free(t_philo *philo);

void	check_for_free_forks(t_philo *philo, t_routine *routine)
{
	if (routine->time_to_look_for_fork == true)
	{
		if (left_and_right_fork_is_free(philo) == true)
		{
			set_forks_are_in_use(philo);
			print_save(FORK, philo);
			print_save(FORK, philo);
			routine->time_to_look_for_fork = false;
			routine->time_to_eat = true;
		}
	}
}


static int	left_and_right_fork_is_free(t_philo *philo)
{
	int	fork_left;
	int	fork_right;

	fork_left = FORK_IN_USE;
	fork_right = FORK_IN_USE;
	pthread_mutex_lock(&philo->protect_fork);
	if (philo->fork == FORK_IS_FREE)
		fork_left = FORK_IS_FREE;
	pthread_mutex_unlock(&philo->protect_fork);
	pthread_mutex_lock(&philo->next_philo->protect_fork);
	if (philo->next_philo->fork == FORK_IS_FREE)
		fork_right = FORK_IS_FREE;
	pthread_mutex_unlock(&philo->next_philo->protect_fork);
	if (fork_left == FORK_IS_FREE && fork_right == FORK_IS_FREE)
		return (true);
	return (false);
}

static void	set_forks_are_in_use(t_philo *philo)
{
	pthread_mutex_lock(&philo->protect_fork);
	pthread_mutex_lock(&philo->next_philo->protect_fork);
	philo->fork = FORK_IN_USE;
	philo->next_philo->fork = FORK_IN_USE;
	pthread_mutex_unlock(&philo->next_philo->protect_fork);
	pthread_mutex_unlock(&philo->protect_fork);
}
