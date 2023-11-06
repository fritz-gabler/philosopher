/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_threas_created.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:24:13 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/06 09:08:28 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_threads_created(t_philo *philo)
{
	while(check_all_threads_created(philo) == false)
	{

		if (threads_creation_failed(philo) == true)
		{
			return (false);
		}
		usleep(50);
	}
	return (true);
}
