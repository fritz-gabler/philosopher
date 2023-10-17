/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:57 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/17 14:33:53 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_input (t_input **input, int ac, char **av)
{
	(*input) = malloc(sizeof(t_input));
	(*input)->ac = ac;
	(*input)->av = av;
}
