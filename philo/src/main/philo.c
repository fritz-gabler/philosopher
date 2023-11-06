/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:02:19 by fgabler           #+#    #+#             */
/*   Updated: 2023/11/06 13:09:34 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_input		*input;
	t_philo		*philo;
	t_table		*table;

	get_input(&input, ac, av);
	if (is_input_valide(input) == false)
		return (1);
	if (create_table(&table, input) == false)
		return (1);
	if (create_philo(&philo, table) == false)
		return (1);
	wait_for_threads(philo, table->nbr_of_philo);
	destroy_all_mutex(philo, table->nbr_of_philo);
	clear_structs(&philo, &table, table->nbr_of_philo);
	return (0);
}
