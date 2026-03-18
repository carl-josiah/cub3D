/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:25:28 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/16 18:43:04 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

# include <libft.h>
# include <structs.h>
# include <defines.h>

void					exit_error(t_data *data, char *msg, char *line, int nl);
void					free_double_ptr(char **ptr);
void					free_textures(t_tex *tex);
void					throw_color_error(t_data *data);
void					throw_direction_error(t_data *data);
void					free_grid(char **grid, int height);
void					free_map(t_data *data);
void					free_all(char **lines, t_data *data);

#endif
