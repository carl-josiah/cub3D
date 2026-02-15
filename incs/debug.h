/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:05:31 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/15 13:52:09 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include <fcntl.h>
# include <libft.h>

int						print_for_me(const char *path);
void					print_grid(const char **grid, int height);

#endif
