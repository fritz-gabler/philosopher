/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:02:41 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/30 17:43:09 by fgabler          ###   ########.fr       */
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
# define FORK_IN_USE				22447
# define FORK_IS_FREE				22447
# define THINK						"is thinking"
# define FORK						"has taken a fork"
# define EAT						"is eating"
# define SLEEP						"is sleeping"
# define DIE						"died"

/*################################INCLUDES###################################*/
/*###########################################################################*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>

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
	unsigned int		nbr_of_philo;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	int					time_each_philo_must_eat;
	int					all_philos_alive;
	pthread_mutex_t		protect_all_alive;
	long long			start_of_dinner;
	pthread_mutex_t		protect_message;
	int					*thread_ids;
	void				*first_philo;
}	t_table;

typedef struct s_philo
{
	pthread_t			*philo;
	int					id;
	int					fork;
	pthread_mutex_t		protect_fork;
	long long			last_time_eating;
	int					times_eaten;
	struct s_philo		*next_philo;
	t_table				*table;
}	t_philo;

typedef struct s_routine
{
	int		think;
	int		eat;
	int		sleeps;
}	t_routine;

/*################################FUNKTIONS##################################*/
/*###########################################################################*/

//INPUT
void			get_input (t_input **input, int ac, char **av);
int				is_input_valide (t_input *input);

//ERROR
void			error(int error);

//UTLIS
int				ft_isdigit(int c);
long			ft_strtol(const char *str);
int				ft_atoi(const char *str);
long long		get_current_time_in_mill();
void			create_mutex(pthread_mutex_t *mutex);
void				sleep_and_death_check(int time_to_sleep, t_philo *philo);

//CREATE
int				create_table(t_table **table, t_input *input);
int				create_philo(t_philo **philo, t_table *table);

//ROUTINE
void			*routine(void *arg);

//ROUTINE_FUNCS
int				find_next_fork(t_philo *philo);
void			print_save(char *message, t_philo *philo);
void			set_routine_struct(t_routine *routine);
int				philo_died(t_philo *philo);
void			philo_is_thinking(t_philo *philo, t_routine *routine);
void			check_for_free_forks(t_philo *philo, t_routine *routine);
void			philo_is_eating(t_philo *philo, t_routine *routine);
void			philo_is_sleeping(t_philo * philo, t_routine *routine);

#endif
