/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:46:29 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/19 13:33:30 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define DEBUG_MAIN 1
# define DEBUG_PARSE 2

# define SPACES " \t\n\v\f\r"

# define ERROR_WITH_MSG "Error: "
# define ERROR_NO_MSG "Error"

# define ERROR_CRLF "CRLF detected"

# define USAGE "Usage: ./cub3D [file_name].cub"
# define MALLOC "Malloc Failure"

# define EMPTY_FILE "Empty File"
# define INVALID_FILE "Invalid .cub file"

# define MAP_CHARS "01NSEW \t\n\v\f\r"
# define MAP_DIRECTIONS "NSEW"

# define DUPLICATE_TEXTURE "Duplicate Texture"
# define INVALID_TEXTURE "Invalid Texture"
# define INVALID_PATH "Invalid Texture Path"
# define INVALID_IDENTIFIER "Invalid Identifier"
# define NO_TEXTURE "No Path Indicated"
# define INCOMPLETE_TEXTURE "Incomplete Configuration\nAdd Direction and Color"
# define INVALID_COLOR "Invalid Color Format"

# define NO_NL 0
# define NL 1

# define MISSING_NO "Missing NO [path]"
# define MISSING_SO "Missing SO [path]"
# define MISSING_EA "Missing EA [path]"
# define MISSING_WE "Missing WE [path]"
# define MISSING_F "Missing F [R,G,B]"
# define MISSING_C "Missing C [R,G,B]"
# define MISSING_MAP "Missing Map"

# define EMPTY_LINE "Empty Line Inside Map"
# define MAP_ERROR_DIR "Must Have One Direction Inside Map"
# define MAP_INVALID_CHARS "Invalid Characters Inside Map"
# define MAP_NOT_CLOSED "Map Is Not Closed"

# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define ERROR_MLX_INIT "MLX initialization failed"
# define ERROR_MLX_WIN "MLX window failed"
# define ERROR_MLX_SCREEN_IMG "MLX screen image failed"
# define ERROR_MLX_SCREEN_ADDR "MLX screen address failed"
# define ERROR_MLX_TEXTURE "MLX load texture failed"
# define CUB3D "cub3D"

# define TEX_COUNT 4

# define MOVE_SPEED 0.02
# define ROT_SPEED 0.03

// keycodes
# ifdef __linux__
#  include <X11/keysym.h>
#  define ESC_KEY XK_Escape
# else
#  define ESC_KEY 53
# endif

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

# define KEY_COUNT 7
# define DESTROY_NOTIFY 17
# define KEY_PRESS 2
# define KEY_RELEASE 3

#endif
