/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 00:38:11 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/01 11:18:39 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo		*philo;
	t_routine	routine;

	philo = (t_philo *) arg;
	set_routine_struct(&routine);

	while (philo->table->run_routine == true)
	{
		philo_is_thinking(philo, &routine);
		check_for_free_forks(philo, &routine);
		philo_is_eating(philo, &routine);
		//check_how_many_times_eaten();
		philo_is_sleeping(philo, &routine);
		philo_died(philo);
		usleep(100);
	}
	return ((void *) philo);
}
