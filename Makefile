# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/23 14:26:02 by ccastro           #+#    #+#              #
#    Updated: 2026/01/31 10:16:09 by ccastro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					:= cub3D
CC						:= cc
CFLAGS					:= -g3 # -Wall -Wextra -Werror

LIBFT_DIR				:= libft-custom
LIBFT					:= $(LIBFT_DIR)/libft.a

SRCS_DIR				:= srcs
OBJS_DIR				:= objs

PARSING_DIR				:= parsing
CLEANUP_DIR				:= cleanup
UTILS_DIR				:= utils
DEBUG_DIR				:= debug

UNAME					:= $(shell uname -s)

ifeq ($(UNAME), Darwin)
    MLX_DIR				:= minilibx_opengl_20191021
    MLX_LIB				:= $(MLX_DIR)/libmlx.a
    MLX_FLAGS			:= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
    MLX_DIR				:= minilibx-linux
    MLX_LIB				:= $(MLX_DIR)/libmlx_Linux.a
    MLX_FLAGS			:= -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm
endif

CFLAGS					+= -I$(MLX_DIR) -Iincs -I$(LIBFT_DIR)/incs

MAIN					:= cub3d.c
PARSING_SRCS			:= validate.c texture.c helpers.c read.c parse.c
CLEANUP_SRCS			:= exit_error.c free.c id_error.c dir_error.c col_error.c
UTILS_SRCS				:= initialize.c
DEBUG_SRCS				:= print.c

ALL_SRCS				:= $(MAIN) \
						   $(addprefix $(PARSING_DIR)/, $(PARSING_SRCS)) \
						   $(addprefix $(CLEANUP_DIR)/, $(CLEANUP_SRCS)) \
						   $(addprefix $(UTILS_DIR)/, $(UTILS_SRCS)) \
						   $(addprefix $(DEBUG_DIR)/, $(DEBUG_SRCS)) \
						   # $(addprefix $(EXECUTION_DIR)/, $(EXECUTION_SRCS)) \

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
