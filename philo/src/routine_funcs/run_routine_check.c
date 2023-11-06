/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_routine_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:57:29 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/06 10:22:25 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_routine_check(t_philo *philo)
{
	int	run_routine;
	pthread_mutex_lock(&philo->table->protect_run_routine);
	if (philo->table->run_routine == true)
		run_routine = true;
	else 
		run_routine = false;
	pthread_mutex_unlock(&philo->table->protect_run_routine);
	if (run_routine == true)
		return (true);
	return (false);
}
