/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 00:38:11 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/03 18:05:11 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo		*philo;
	t_routine	routine;

	philo = (t_philo *) arg;
	set_routine_struct(&routine);
	while (run_routine_check(philo) == true)
	{
		check_for_free_forks(philo, &routine);
		philo_is_eating(philo, &routine);
		philo_is_sleeping(philo, &routine);
		philo_is_thinking(philo, &routine);
		philo_died(philo);
	}
	return ((void *) philo);
}
