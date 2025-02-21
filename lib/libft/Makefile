# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 17:14:39 by pepaloma          #+#    #+#              #
#    Updated: 2025/02/21 04:05:21 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target Binary Program
NAME	:= libft.a

# Directories
SRC_DIR	:= src
INC_DIR	:= inc
OBJ_DIR	:= obj
BIN_DIR	:= bin

# Compilation flas
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
HEADERS			= -I$(INC_DIR)

SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all : $(NAME)

$(NAME) : $(OBJ_FILES) | $(BIN_DIR)
	ar rcs $(BIN_DIR)/$(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(HEADERS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) :
	mkdir -p $(BIN_DIR)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(BIN_DIR)

re : fclean all

.PHONY: all re clean fclean
