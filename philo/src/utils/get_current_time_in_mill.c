/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time_in_mill.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:35:23 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/06 13:00:20 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_current_time_in_mill(void)
{
	struct timeval	start_time;
	long long		time_in_mill;

	gettimeofday(&start_time, NULL);
	time_in_mill = (start_time.tv_sec) * 1000 + (start_time.tv_usec) / 1000;
	return (time_in_mill);
}
