/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_routine_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:57:29 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/03 17:03:38 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_routine_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect_run_routine);
	if (philo->table->run_routine == true)
	{
		pthread_mutex_unlock(&philo->table->protect_run_routine);
		return (true);
	}
	pthread_mutex_unlock(&philo->table->protect_run_routine);
	return (false);
}
