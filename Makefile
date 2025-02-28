# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 20:02:41 by pepaloma          #+#    #+#              #
#    Updated: 2025/02/21 19:00:23 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target binary program
NAME	:= miniRT

# Directories
LIB_DIR	:= lib
FT_DIR	:= $(LIB_DIR)/libft
MLX_DIR	:= $(LIB_DIR)/MLX42
SRC_DIR	:= src
INC_DIR	:= inc
OBJ_DIR	:= obj
BIN_DIR	:= bin

# Compilation flas
CFLAGS	:= -Wextra -Wall -Werror
HEADERS	:= -I$(INC_DIR) -I$(MLX_DIR)/include/MLX42 -I$(FT_DIR)/$(INC_DIR)
LDFLAGS	:= -L$(MLX_DIR)/build -L/opt/homebrew/opt/glfw/lib -L$(FT_DIR)/$(BIN_DIR)
LDLIBS	:= -lmlx42 -lft -ldl -lglfw -pthread -lm

# Files
SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
MLX_LIB := $(MLX_DIR)/build/libmlx42.a
FT_LIB := $(FT_DIR)/$(BIN_DIR)/libft.a

# Rules
all: $(BIN_DIR)/$(NAME)

$(BIN_DIR)/$(NAME): $(OBJ_FILES) $(FT_LIB) $(MLX_LIB) | $(BIN_DIR)
	$(CC) $(OBJ_FILES) $(LDFLAGS) $(LDLIBS) $(HEADERS) -o $(BIN_DIR)/$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(HEADERS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) :
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

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
	rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re
