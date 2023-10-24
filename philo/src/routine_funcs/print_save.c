/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:38:00 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/22 14:06:52 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_save(char *message, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print_save);
	printf("%s\n", get_time,philo->id, message);
	pthread_mutex_unlock(&philo->table->print_save);
}
