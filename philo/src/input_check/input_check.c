/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:31:51 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/13 16:37:09 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_check(t_input input)
{
	if (input.ac != 6)
		return (error(WRONG_NUMBER_OF_ARGS), 1);
	if (input.av[1] < 
}
