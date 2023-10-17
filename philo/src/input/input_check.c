/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:31:51 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/17 22:35:25 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	not_numer (t_input *input);
static int	bigger_max_int (t_input *input);
static int zero_or_less_philo (t_input *input);

int	is_input_valide (t_input *input)
{
	if (input->ac < 5 || input->ac > 6)
		return (error(WRONG_NUMBER_OF_ARGS), free(input), false);
	if (not_numer(input) == true)
		return (error(ARG_IS_NOT_NUMER), free(input), false);
	if (bigger_max_int(input) == true)
		return (error(ARG_BIGGER_MAX_INT), free(input), false);
	if (zero_or_less_philo(input) == true)
		return (error(NOT_ENAUGE_PHILOS), free(input), false);
	return (true);
}

static int	not_numer (t_input *input)
{
	int		i;
	int		j;

	i = 1;
	while (i < input->ac)
	{
		j = 0;
		while (input->av[i][j])
		{
			if (ft_isdigit(input->av[i][j]) == false)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static int	bigger_max_int (t_input *input)
{
	int		i;

	i = 0;
	while (i < input->ac)
	{
		if (ft_strtol(input->av[i]) > INT_MAX)
			return (true);
		i++;
	}
	return (false);
}

static int zero_or_less_philo (t_input *input)
{
	if (ft_atoi(input->av[1]) < 1)
		return (true);
	return (false);
}
