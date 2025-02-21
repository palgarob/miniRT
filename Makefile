# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 20:02:41 by pepaloma          #+#    #+#              #
#    Updated: 2025/02/20 23:56:00 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= miniRT

FT_DIR	:= libft
MLX_DIR	:= MLX42
SRC_DIR	:= src
INC_DIR	:= inc
OBJ_DIR	:= obj
MLX_LIB := $(MLX_DIR)/build/libmlx42.a
FT_LIB := $(FT_DIR)/libft.a

CFLAGS	:= -Wextra -Wall -Werror -g
HEADERS	:= -I$(INC_DIR) -I$(MLX_DIR)/include/MLX42 -I$(FT_DIR)/inc
LDFLAGS	:= -L$(MLX_DIR)/build -L/opt/homebrew/opt/glfw/lib -L$(FT_DIR)
LDLIBS	:= -lmlx42 -lft -ldl -lglfw -pthread -lm

SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ_FILES) $(FT_LIB) $(MLX_LIB)
	$(CC) $(OBJ_FILES) $(LDFLAGS) $(LDLIBS) $(HEADERS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(HEADERS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(FT_LIB):
	$(MAKE) -C $(FT_DIR)

$(MLX_LIB):
	@mkdir -p $(MLX_DIR)/build
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build -j4

clean:
	$(MAKE) -C $(FT_DIR) fclean
	rm -rf $(OBJ_DIR)
	rm -rf $(MLX_DIR)/build

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
