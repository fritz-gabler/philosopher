/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_and_death_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:20:02 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/06 15:19:50 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_and_death_check(int time_to_sleep, t_philo *philo)
{
	long long	start;

	start = get_current_time_in_mill();
	while ((get_current_time_in_mill() - start) <= ((long long) time_to_sleep))
	{
		usleep(USLEEP);
		if (philo_died(philo) == true)
			return ;
	}
}
