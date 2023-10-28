/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_routine_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:23:05 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/28 13:25:03 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_routine_struct(t_routine *routine)
{
	routine->think = true;
	routine->eat = false;
	routine->sleeps = false;
}
