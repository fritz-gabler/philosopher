/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 00:38:11 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/06 13:04:25 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_routine_check(t_philo **philo, t_routine *routine, void *arg);

void	*routine(void *arg)
{
	t_philo		*philo;
	t_routine	routine;

	if (start_routine_check(&philo, &routine, arg) == false)
		return ((void *) philo);
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

static int	start_routine_check(t_philo **philo, t_routine *routine, void *arg)
{
	*philo = (t_philo *) arg;
	if (all_threads_created(*philo) == false)
		return (false);
	if (single_meal(*philo) == true)
		return (false);
	set_routine_struct(routine);
	return (true);
}
