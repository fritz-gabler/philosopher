/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:38:00 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/07 11:15:45 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	get_time(t_philo *philo);

void	print_save(char *message, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect_message);
	if (run_routine_check(philo) == true)
		printf("%llu %d %s\n", get_time(philo), philo->id, message);
	pthread_mutex_unlock(&philo->table->protect_message);
}

static long long	get_time(t_philo *philo)
{
	long long	get_time;

	pthread_mutex_lock(&philo->table->protect_start_time);
	get_time = get_current_time_in_mill() - philo->table->start_of_dinner;
	pthread_mutex_unlock(&philo->table->protect_start_time);
	return (get_time);
}
