# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/23 14:26:02 by ccastro           #+#    #+#              #
#    Updated: 2026/05/15 10:45:05 by ccastro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					:= cub3D
CC						:= cc
CFLAGS					:= -Wall -Wextra -Werror

LIBFT_DIR				:= libft-custom
LIBFT					:= $(LIBFT_DIR)/libft.a

SRCS_DIR				:= srcs
OBJS_DIR				:= objs

PARSE_DIR				:= parse
EXECUTE_DIR				:= execute
CLEANUP_DIR				:= cleanup
INITIALIZE_DIR			:= initialize
DEBUG_DIR				:= debug

UNAME					:= $(shell uname -s)

ifeq ($(UNAME), Darwin)
    MLX_DIR				:= minilibx_darwin
    MLX_LIB				:= $(MLX_DIR)/libmlx.a
    MLX_FLAGS			:= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
    MLX_DIR				:= minilibx-linux
    MLX_LIB				:= $(MLX_DIR)/libmlx_Linux.a
    MLX_FLAGS			:= -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm
endif

CFLAGS					+= -I$(MLX_DIR) -Iincs -I$(LIBFT_DIR)/incs

MAIN					:= cub3d.c
PARSE_SRCS				:= validate.c texture.c texture_utils.c read.c parse.c map.c map_utils.c
EXECUTE_SRCS			:= execute.c hooks.c mlx.c movement.c render.c raycast.c raycast_utils.c
CLEANUP_SRCS			:= parse_errors.c exit_error.c cleanup_parse.c cleanup_execution.c free_all.c
INITIALIZE_SRCS			:= init_parse.c init_exec.c init.c
DEBUG_SRCS				:= print.c

ALL_SRCS				:= $(MAIN) \
						   $(addprefix $(PARSE_DIR)/, $(PARSE_SRCS)) \
						   $(addprefix $(CLEANUP_DIR)/, $(CLEANUP_SRCS)) \
						   $(addprefix $(INITIALIZE_DIR)/, $(INITIALIZE_SRCS)) \
						   $(addprefix $(DEBUG_DIR)/, $(DEBUG_SRCS)) \
						   $(addprefix $(EXECUTE_DIR)/, $(EXECUTE_SRCS)) \

SRCS					:= $(addprefix $(SRCS_DIR)/, $(ALL_SRCS))
OBJS					:= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
