/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:24:54 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/02 15:13:04 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <parsing.h>
#include <stdlib.h>
#define ERROR "Usage: ./cub3D [file_name].cub"

static void	exit_error(void)
{
	ft_putstr_fd(ERROR, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(2);
}

static void	argc_validation(int ac)
{
	if (ac != 2)
		exit_error();
}

static void	argv_validation(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isspace(arg[i]))
			exit_error();
		i++;
	}
	if (i < 5)
		exit_error();
	i -= 4;
	if (ft_strncmp(".cub", &arg[i], 4))
		exit_error();
}

void	args_validation(int ac, char **av)
{
	argc_validation(ac);
	argv_validation(*(av + 1));
}
