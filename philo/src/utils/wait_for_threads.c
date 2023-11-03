/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:02:10 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/03 10:59:59 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_threads(t_philo *philo)
{
	unsigned int		i;
	t_philo	*tmp_philo;

	i = 0;
	tmp_philo = philo;
	while (i < philo->table->nbr_of_philo)
	{
		pthread_join(tmp_philo->philo, NULL);
		tmp_philo = tmp_philo->next_philo;
		i++;
	}
}
