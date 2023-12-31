/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:02:41 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/16 11:40:23 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*##########################FILE_DEFINITION##################################*/
/*###########################################################################*/

# ifndef PHILO_H
# define PHILO_H

/*###############################DEFINITION##################################*/
/*###########################################################################*/

# define RED						"\x01\033[1;31m\x02"
# define DARK_GREEN					"\x01\033[1;32m\x02"
# define GRASS_GREEN				"\x01\033[38;2;0;255;0m\x02"
# define YELLOW						"\x01\033[1;33m\x02"
# define MAGENTA					"\x01\033[1;35m\x02"
# define BLUE						"\x01\033[1;34m\x02"
# define WHITE						"\x01\033[0m\x02"
# define ORANGE						"\x01\033[38;2;255;165;0m\x02"
# define RESET						"\033[0m"
# define WRONG_NUMBER_OF_ARGS		22443
# define ARG_BIGGER_MAX_INT			22444
# define ARG_IS_NOT_NUMER			22445
# define NOT_ENAUGE_PHILOS			22446
# define FORK						"has taken a fork"
# define EAT						"is eating"
# define SLEEP						"is sleeping"
# define THINK						"is thinking"
# define DIE						"died"

/*################################INCLUDES###################################*/
/*###########################################################################*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

/*###############################DEFINITION##################################*/
/*###########################################################################*/

typedef enum e_bool{false, true}	t_bool;

typedef struct s_input
{
	int					ac;
	char				**av;
}	t_input;

typedef struct s_table
{
	int					nbr_of_philos;
	char				*forks;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	pthread_mutex_t		table_mutex;
}	t_table;

typedef struct s_status
{
	t_bool				philo_died;
	int					is_sleeping;
	t_table				*table;
}	t_status;

typedef struct s_philo
{
	int					nbr_of_philos;
	pthread_mutex_t		philo_mutex;
	t_status			*status;
}	t_philo;

/*################################FUNKTIONS##################################*/
/*###########################################################################*/

#endif
