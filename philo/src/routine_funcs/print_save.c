/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:38:00 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/31 16:38:32 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_save(char *message, t_philo *philo)
{
	if (philo->table->run_routine == true)
	{
		pthread_mutex_lock(&philo->table->protect_message);
		printf("%llu %d %s\n",
				(get_current_time_in_mill() - philo->table->start_of_dinner),
				philo->id, message);
		pthread_mutex_unlock(&philo->table->protect_message);
	}
}
