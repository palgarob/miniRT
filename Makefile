# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 20:02:41 by pepaloma          #+#    #+#              #
#    Updated: 2024/12/23 20:56:58 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= miniRT

# FT_DIR	= libft
MLX_DIR	= MLX42
SRC_DIR	= src
INC_DIR	= inc

CFLAGS	:= -Wextra -Wall -Werror -g

HEADERS	:= -I$(INC_DIR) -I$(MLX_DIR)/include/MLX42 # -I$(FT_DIR)/inc 
LDFLAGS	:= -L$(MLX_DIR)/build -L/opt/homebrew/opt/glfw/lib # -L$(FT_DIR)
# ¿¿¿??? cuando utilizo glfw en apple silicon así es como hago la referencia y funciona, pero aparece esto en la terminal cuando lo ejecutas:

# UNSUPPORTED (log once): POSSIBLE ISSUE: unit 1 GLD_TEXTURE_INDEX_2D is unloadable and bound to sampler type (Float) - using zero texture because texture unloadable
# 2024-10-28 09:37:08.200 miniRT[74919:4218338] +[IMKClient subclass]: chose IMKClient_Legacy
# 2024-10-28 09:37:08.200 miniRT[74919:4218338] +[IMKInputSession subclass]: chose IMKInputSession_Legacy

LDLIBS	:= -lmlx42 -lft -ldl -lglfw -pthread -lm

SRC		= $(basename $(notdir $(wildcard src/*.c)))
OBJ		= $(addsuffix .o,$(basename $(SRC)))

all: $(NAME)

$(NAME): libft $(OBJ)
	mkdir -p $(MLX_DIR)/build && cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	cmake --build $(MLX_DIR)/build -j4
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) $(HEADERS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

#libft:
#	$(MAKE) -C $(FT_DIR);

clean:
	$(MAKE) -C $(FT_DIR) fclean
	rm -rf $(OBJ_DIR)
	rm -rf $(MLX_DIR)/build

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libft
