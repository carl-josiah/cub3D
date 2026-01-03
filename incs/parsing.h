/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:25:39 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/02 18:27:36 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>

# define DEBUG 1

void					args_validation(int ac, char **av);

#endif
