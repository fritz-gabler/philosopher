/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:55:18 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/05 12:53:42 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_all_mutex(t_philo *philo, int nbr_of_threads)
{
	int		i;
	t_philo	*tmp_philo;

	i = 0;
	tmp_philo = philo;
	while (i < nbr_of_threads && tmp_philo)
	{
		
		pthread_mutex_destroy(&tmp_philo->protect_fork);
		pthread_mutex_destroy(&tmp_philo->protect_times_eaten);
		tmp_philo = tmp_philo->next_philo;
		i++;
	}
	pthread_mutex_destroy(&philo->table->protect_dinner_served);
	pthread_mutex_destroy(&philo->table->protect_run_routine);
	pthread_mutex_destroy(&philo->table->protect_message);
}
