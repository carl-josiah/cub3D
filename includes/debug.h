/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:05:31 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/12 16:42:26 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "libft.h"
# include "structs.h"
# include <fcntl.h>

int		print_for_me(const char *path);
void	print_grid(char **grid, int height);
void	print_texture_paths(t_data *data);
void	print_center_ray(t_ray *ray);
void	print_file_lines(char **lines);

#endif
