NAME = philo

HEADER = includes/philo.h

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRCS = src/philo.c src/philo_utils.c src/philo_actions.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) 
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "\033[92mPhilosophers made🤔\033[0m"

clean:
	@rm -f $(OBJS)
	@echo "\033[1;34mA\033[1;31ml\033[1;32ml \033[1;33mc\033[1;30ml\033[1;35me\033[1;36ma\033[1;37mn🧼\033[0m"

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@echo "\033[0;31mPhilosophers killed💀❌\033[0m"

re:	fclean all

.PHONY: all clean fclean re