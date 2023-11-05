/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_meal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:33:39 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/05 11:34:14 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_till_philo_died(t_philo *philo);

int	single_meal(t_philo *philo)
{
	if (philo->table->single_meal == true)
	{
		wait_till_philo_died(philo);
		return (true);
	}
	return (false);
}

static void	wait_till_philo_died(t_philo *philo)
{
	while(philo_died( philo) == false)
		usleep(1000);
	return ;
}
