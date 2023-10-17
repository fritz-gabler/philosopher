/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:40:05 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/17 15:53:42 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(int error)
{
	if (error == WRONG_NUMBER_OF_ARGS)
		printf("%sNumber of arguments is wrong\n%s", RED, RESET);
	if (error == ARG_BIGGER_MAX_INT)
		printf("%sArgumen is bigger than INT_MAX\n%s", RED, RESET);
	if (error == WRONG_NUMBER_OF_ARGS)
		printf("%sNumber of arguments is wrong\n%s", RED, RESET);
	if (error == WRONG_NUMBER_OF_ARGS)
		printf("%sNumber of arguments is wrong\n%s", RED, RESET);
}
