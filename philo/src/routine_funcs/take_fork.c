/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:14:15 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/22 13:43:45 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, int next_or_own)
{
	if (next_or_own == NEXT_FORK)
	{
		pthread_mutex_lock(&philo->table->fork[find_next_fork(philo)]);
		print_save(FORK, philo);
	}
	if (next_or_own == OWN_FORK)
	{
		pthread_mutex_lock(&philo->table->fork[philo->id]);
	}
}
