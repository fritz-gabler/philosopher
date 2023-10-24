/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 09:28:16 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/22 09:33:26 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	find_next_fork(t_philo *philo)
{
	int pos_sec;

	pos_sec = philo->table->nbr_of_philos % philo->id;
	return (pos_sec);
}
