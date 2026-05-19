/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:25:39 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/15 15:06:23 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cleanup.h"
# include "debug.h"
# include "defines.h"
# include "errno.h"
# include "initialize.h"
# include "libft.h"
# include "structs.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

void			args_validation(int ac, char **av);
void			parse_direction(int id, char *line, t_data *data);
void			parse_color(int id, char *line, t_tex *tex);
t_tex_status	is_texture(int *id, char *line, t_tex *tex);
char			**read_cub_file(t_data *data, const char *cub_file, size_t *lc);
void			parse_file(char **lines, t_data *data);
void			skip_white_spaces(char **line, int skip);
void			throw_id_error(int id, t_tex *tex);
void			forbid_garbage(char *ptr, char *line);
void			store_map_line(char *map_line, t_data *data);
int				parse_rgb_channel(char *ptr, int *rgb, int i);
void			validate_map(char **grid, t_data *data);
int				count_directions(char **grid, int height);
int				count_map_height(char **line);
char			**copy_grid(char **grid, int height);
void			find_player(t_data *data);
void			set_spawn_north(t_data *data);
void			set_spawn_south(t_data *data);
void			set_spawn_east(t_data *data);
void			set_spawn_west(t_data *data);

#endif
