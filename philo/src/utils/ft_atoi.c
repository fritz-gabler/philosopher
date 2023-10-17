/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:46:12 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/17 15:46:32 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_isspace(const char *str, int *pos)
{
	while (str[*pos] == ' ' || str[*pos] == '\r' || str[*pos] == '\t'
		|| str[*pos] == '\f' || str[*pos] == '\v' || str[*pos] == '\n')
	{
		if (ft_isdigit(str[*pos]))
			return ;
		(*pos)++;
	}
}

static void	ft_checksigne(const char *str, int *pos, int *neg)
{
	if (str[*pos] == '-' || str[*pos] == '+')
	{
		if (str[(*pos)++] == '-')
			*neg = -1;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	res = 0;
	neg = 1;
	ft_isspace(str, &i);
	ft_checksigne(str, &i, &neg);
	while (str[i] && ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * neg);
}
