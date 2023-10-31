/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_thinking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:23:08 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/30 18:25:44 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_is_thinking(t_philo *philo, t_routine *routine)
{
	if (routine->think == true)
	{
		print_save(THINK, philo);
		routine->think = false;
	}
}