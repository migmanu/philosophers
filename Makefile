# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migmanu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 19:24:44 by migmanu           #+#    #+#              #
#    Updated: 2023/10/27 19:02:45 by migmanu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCES
SRCS_DIR = ./src
SRCS = $(wildcard $(SRCS_DIR)/*/*.c)
SRCS += $(wildcard $(SRCS_DIR)/main.c)

OBJ_FILES = $(patsubst %.c, %.o, $(SRCS))

CFLAGS = -pthread -Wall -Werror -Wextra -g

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

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo $(RED) "Cleaning..." $(EOC)
	@$(RM) $(OBJ_FILES)

fclean: clean
	@echo $(PURPLE) "Full Cleaning...🧹" $(EOC)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean

