/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:43:34 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/20 00:41:20 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo (t_philo **philo, t_table *table)
{
	int		i;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		(*philo) = malloc(sizeof(t_philo));
		pthread_create((*philo)->philo, NULL, &routine, &philo);
		(*philo)->id = i;
		(*philo)->table = table;
		i++;
	}
	return (true);
}
