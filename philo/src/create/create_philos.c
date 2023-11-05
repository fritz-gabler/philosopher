/*/ ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:43:34 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/05 09:16:32 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_philo **philo, t_table *table)
{
	if (create_philo_struct(philo, table) == false)
		return (false);
	if (create_philo_threads(*philo) == false)
		return (false);
	*philo = table->first_philo;
	return (true);
}
