/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:12:45 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/04 14:12:13 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo_threads(t_philo *philo)
{
	unsigned int	i;
	t_philo			*tmp_philo;

	i = 0;
	tmp_philo = philo;
	while (i < philo->table->nbr_of_philo)
	{
		pthread_create(&tmp_philo->philo, NULL, &routine, tmp_philo);
		tmp_philo = tmp_philo->next_philo;
		i++;
	}
}

