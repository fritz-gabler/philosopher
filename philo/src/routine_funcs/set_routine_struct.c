/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_routine_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:23:05 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/01 11:08:38 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_routine_struct(t_routine *routine)
{
	routine->time_to_think = true;
	routine->time_to_eat = false;
	routine->time_to_sleep = false;
	routine->time_to_look_for_fork = false;
}
