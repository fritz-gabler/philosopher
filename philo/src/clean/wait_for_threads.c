/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:02:10 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/05 12:54:15 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_threads(t_philo *philo, int nbr_of_threads)
{
	int		i;
	t_philo	*tmp_philo;

	i = 0;
	tmp_philo = philo;
	while (i < nbr_of_threads && tmp_philo)
	{
		pthread_join(tmp_philo->philo, NULL);
		tmp_philo = tmp_philo->next_philo;
		i++;
	}
}
