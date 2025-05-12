# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 14:05:04 by mmouaffa          #+#    #+#              #
#    Updated: 2024/11/15 13:46:44 by mmouaffa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap

SRCS    = $(wildcard src/*.c)
OBJS    = $(SRCS:.c=.o)

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -Iincludes -g

RM      = rm -rf

X       = \033[0m
R       = \033[0;31m
G       = \033[0;32m
Y       = \033[0;33m
B       = \033[0;34m

define LOADING_ANIMATION
	@echo "$(B)Compiling$(X)"; \
	for i in {1..3}; do \
		echo "."; \
		sleep 0.2; \
	done; \

endef

define CLEAN_ANIMATION
	@echo "$(R)Cleaning$(X)"; \
	for i in {1..3}; do \
		echo "."; \
		sleep 0.2; \
	done; \

endef

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null 2>&1

all: $(NAME)

$(NAME): $(OBJS)
	$(LOADING_ANIMATION)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) > /dev/null 2>&1
	@echo "$(G)Finished [$(NAME)]$(X)"

clean:
	$(CLEAN_ANIMATION)
	@$(RM) $(OBJS)
	@echo "$(R)Removed objects$(X)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(R)Removed executable $(NAME)$(X)"

re: fclean all

norm:
	@echo "$(Y)Running norminette on source files...$(X)"
	@norminette $(SRCS)

.PHONY: all clean fclean re norm
