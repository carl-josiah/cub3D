/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:46:29 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/10 16:36:43 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define DEBUG_MAIN 1
# define DEBUG_PARSE 2

# define SPACES " \t\n\v\f\r"

# define ERROR_WITH_MSG "Error: "
# define ERROR_NO_MSG "Error"

# define USAGE "Usage: ./cub3D [file_name].cub"
# define MALLOC "Malloc Failure"

# define EMPTY_FILE "Empty File"

# define MAP "01NSEW \t\n\v\f\r"
# define DUPLICATE_TEXTURE "Duplicate Texture"
# define INVALID_TEXTURE "Invalid Texture"
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

#endif
