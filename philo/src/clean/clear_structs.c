/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:35:56 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/06 16:47:12 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clear_philos(t_philo **philo, int nbr_of_philos);
static void	clear_table(t_table **table);

void	clear_structs(t_philo **philo, t_table **table, int nbr_of_philo)
{
	clear_philos(philo, nbr_of_philo);
	clear_table(table);
}

static void	clear_philos(t_philo **philo, int nbr_of_philos)
{
	t_philo	*tmp_philo;
	int		i;

	i = 0;
	while (i < nbr_of_philos)
	{
		tmp_philo = (*philo)->next_philo;
		if (*philo != NULL)
			free(*philo);
		*philo = tmp_philo;
		i++;
	}
	philo = NULL;
}

static void	clear_table(t_table **table)
{
	free(*table);
	*table = NULL;
}
