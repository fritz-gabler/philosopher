/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:12:45 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/04 18:39:39 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clean_failed_thread(t_philo *philo, int nbr_of_threads);

int	create_philo_threads(t_philo *philo)
{
	unsigned int	i;
	t_philo			*tmp_philo;

	i = 0;
	tmp_philo = philo;
	while (i < philo->table->nbr_of_philo)
	{
		if (pthread_create(&tmp_philo->philo, NULL, &routine, tmp_philo) != 0)
			return (clean_failed_thread(philo, i), false);
		tmp_philo = tmp_philo->next_philo;
		i++;
	}
	return (true);
}

static void	clean_failed_thread(t_philo *philo, int nbr_of_threads)
{
	wait_for_threads(philo, nbr_of_threads);
	destroy_all_mutex(philo, nbr_of_threads);
	clear_structs(&philo, &philo->table, nbr_of_threads);
}
