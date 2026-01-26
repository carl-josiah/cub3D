/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:25:39 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/25 19:10:28 by ccastro          ###   ########.fr       */
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
int						is_empty(char *line);
int						is_map_line(char *line);
char					**read_cub_file(const char *cub_file);
void					parse_file(char **lines, t_data *data);
void					skip_white_spaces(char **line, int skip);
void					throw_id_error(int id, t_tex *tex);

#endif
