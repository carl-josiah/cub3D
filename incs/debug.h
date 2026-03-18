/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:05:31 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/16 18:38:33 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include <fcntl.h>
# include <libft.h>
# include <structs.h>

int						print_for_me(const char *path);
void					print_grid(char **grid, int height);

#endif
