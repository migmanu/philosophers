# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migmanu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 19:24:44 by migmanu           #+#    #+#              #
#    Updated: 2024/01/09 13:15:32 by jmigoya-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCES
SRCS_DIR = ./src/
FILES = main.c actions.c ft_atoi.c start_threads.c check_args.c \
	   initiate.c monitor.c utils.c

SRCS = $(addprefix $(SRCS_DIR), $(FILES))

OBJ_DIR = ./obj/
OBJ_FILES = $(patsubst $(SRCS_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

CFLAGS = -Wall -Werror -Wextra -pthread -g

# COMPILATION
NAME = philosophers
CC = cc
RM = rm -f

# COLORS
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo $(CYAN) "Compiling $@...🛠️" $(EOC)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)
	@echo $(GREEN) "OK COMPILED" $(EOC)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo $(RED) "Cleaning $(NAME)..." $(EOC)
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo $(PURPLE) "Full Cleaning...🧹" $(EOC)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean

