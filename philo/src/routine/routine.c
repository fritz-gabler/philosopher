/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 00:38:11 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/28 14:01:20 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo		*philo;
	t_routine	routine;

	philo = (t_philo *) arg;
	set_routine_struct(&routine);
	while (philo->table->all_philos_alive == true)
	{
		philo_is_thinking(philo, &routine);
		//check_for_free_forks();
		//philo_is_eating();
		//philo_is_sleeping();
		//check_how_many_times_eaten();
		//check_if_philo_died();
	}
}
