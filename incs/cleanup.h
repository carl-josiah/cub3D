/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:25:28 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/18 07:28:50 by ccastro          ###   ########.fr       */
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

#endif
