/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:42:56 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/17 15:33:17 by fgabler          ###   ########.fr       */
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

long	ft_strtol(const char *str)
{
	int		i;
	int		neg;
	long	res;

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
