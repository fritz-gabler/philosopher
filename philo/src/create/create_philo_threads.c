/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:12:45 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/06 14:01:03 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	one_philo(t_philo *philo);
static void	clean_failed_thread(t_philo *philo, int nbr_of_threads);

int	create_philo_threads(t_philo *philo)
{
	unsigned int	i;
	t_philo			*tmp_philo;

	i = 0;
	tmp_philo = philo;
	if (one_philo(tmp_philo) == true)
		return (true);
	while (i < philo->table->nbr_of_philo)
	{
		if (pthread_create(&tmp_philo->philo, NULL, &routine, tmp_philo) != 0)
			return (clean_failed_thread(philo, i), false);
		tmp_philo = tmp_philo->next_philo;
		i++;
	}
	set_all_threads_created(philo);
	return (true);
}

static void	clean_failed_thread(t_philo *philo, int nbr_of_threads)
{
	set_creation_failed(philo);
	wait_for_threads(philo, nbr_of_threads);
	destroy_all_mutex(philo, nbr_of_threads);
	clear_structs(&philo, &philo->table, nbr_of_threads - 2);
}

static int	one_philo(t_philo *philo)
{
	if (philo->table->single_meal == true)
	{
		if (pthread_create(&philo->philo, NULL, &routine, philo) != 0)
			return (clean_failed_thread(philo, 1), true);
		set_all_threads_created(philo);
		return (true);
	}
	return (false);
}
