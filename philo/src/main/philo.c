/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:02:19 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/19 11:42:03 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main (int ac, char **av)
{
	t_input		*input;
//	t_philo		*philo;
	t_table		*table;

	get_input(&input, ac, av);
	if (is_input_valide(input) == false)
		return (1);
	if (create_table(&table, input) == false)
		return (1);
//	if (create_philos(philo, table) == false)
//	clear_structs(philo);
	return (0);
}
