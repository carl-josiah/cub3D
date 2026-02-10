/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:25:39 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/08 11:39:19 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>

# include <libft.h>
# include <defines.h>
# include <structs.h>
# include <cleanup.h>
# include <utils.h>

void					args_validation(int ac, char **av);
void					parse_direction(int id, char *line, t_tex *tex);
void					parse_color(int id, char *line, t_tex *tex);
t_tex_status			is_texture(int *id, char *line, t_tex *tex);
char					**read_cub_file(const char *cub_file);
void					parse_file(char **lines, t_data *data);
void					skip_white_spaces(char **line, int skip);
void					throw_id_error(int id, t_tex *tex);
int						rgb_to_int(int r, int g, int b);
void					forbid_garbage(char *ptr, char *line);

#endif
