###############################################################################
###############################################################################

NAME = philo

###############################################################################
###############################################################################

CC			:=			cc
HEADERS 	:=			-I./include
CFLAGS		?=			-Wall -Werror -Wextra

###############################################################################
###############################################################################

VPATH		:=			src/create src/error src/input src/main src/utils	\
						src/routine_funcs src/routine src/clean
SRC_CLEAR	:=			clear_structs.c wait_for_threads.c					\
						destroy_all_mutex.c
SRC_CREATE	:=			create_table.c create_philos.c						\
						create_philo_struct.c create_philo_threads.c
SRC_ERROR	:=			error.c
SRC_INPUT	:=			input_check.c get_input.c
SRC_MAIN	:=			philo.c
SRC_UTILS	:=			ft_atoi.c ft_isdigit.c ft_strtol.c					\
						get_current_time_in_mill.c							\
						sleep_and_death_check.c ft_bzero.c
SRC_ROUTINE_FUNKS:=		philo_died.c philo_is_thinking.c print_save.c		\
						set_routine_struct.c check_for_free_forks.c			\
						philo_is_eating.c philo_is_sleeping.c				\
						run_routine_check.c check_times_eaten.c				\
						all_threas_created.c single_meal.c					\
						thread_creation_protection.c
SRC_ROUTINE:=			routine.c

SRCS		:=			$(SRC_CREATE) $(SRC_ERROR) $(SRC_INPUT) $(SRC_MAIN)	\
						$(SRC_UTILS) $(SRC_ROUTINE_FUNKS) $(SRC_ROUTINE)	\
						$(SRC_CLEAR)

###############################################################################
###############################################################################

OBJ_DIR		:=			./_obj
OBJ			:=			$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

###############################################################################
###############################################################################

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lpthread
	@printf "$(_SUCCESS) phlio executable is build.\n"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p _obj
	@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@

###############################################################################
###############################################################################

clean:
	@printf $(UP)$(CUT)
	@if [ -d "${OBJ_DIR}" ]; then \
		echo $(RED)Cleaning"  "[$(OBJ_DIR)]...$(RESET); \
		rm -rf ${OBJ_DIR}; \
		echo $(GREEN)Cleaned!$(RESET); \
	fi

fclean: clean
	@echo $(RED)Cleaning executables...
	@printf $(UP)$(CUT)
	@if [ -f $(NAME) ]; then \
		echo $(RED)Cleaning"  "[$(NAME)]...$(RESET); \
		rm -f $(NAME); \
		echo $(GREEN)Cleaned!$(RESET); \
	fi

re: fclean all


###############################################################################
###############################################################################

YELLOW		:=		"\033[33m"
RED			:=			"\033[31m"
GREEN		:=		"\033[32m"
RESET		:=		"\033[0m"
G			=		\e[38;5;118m
YE			=		\e[38;5;226m
RE			=		\e[0m
UP			:=			"\033[A"
CUT			:=			"\033[K"
_SUCCESS	=	$(RE)[$(G)SUCCESS$(RE)]
_INFO		=	[$(YE)INFO$(RE)]
