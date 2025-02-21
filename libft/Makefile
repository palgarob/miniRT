# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 17:14:39 by pepaloma          #+#    #+#              #
#    Updated: 2025/01/30 10:15:17 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The Target Binary Program
NAME	= libft.a

# Directories
SRC_DIR		= src
INC_DIR		= inc
OBJ_DIR	= obj

# Compiler, flags includes
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
HEADERS			= -I$(INC_DIR)

#-------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#-------------------------------------------------------------------------------

SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

.PHONY: all re clean fclean
#.SILENT :

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(HEADERS) $(CFLAGS) -c $< -o $@

re : fclean all

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJ_FILES)
