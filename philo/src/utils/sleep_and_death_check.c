/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_and_death_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:20:02 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/03 10:01:29 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_and_death_check(int time_to_sleep, t_philo *philo)
{
	long long	start;

	start = get_current_time_in_mill();
	while ((get_current_time_in_mill() - start) <= ((long long) time_to_sleep))
	{
		usleep(50);
		if (philo_died(philo) == true)
			return ;
	}
}
