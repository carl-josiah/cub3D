/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:24:54 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/24 13:15:18 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	argc_validation(int ac)
{
	if (ac != 2)
		exit_error(NULL, USAGE, NULL, NL);
}

static void	argv_validation(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isspace(arg[i]))
			exit_error(NULL, USAGE, NULL, NL);
		i++;
	}
	if (i < 5)
		exit_error(NULL, USAGE, NULL, NL);
	i -= 4;
	if (ft_strncmp(".cub", &arg[i], 4))
		exit_error(NULL, USAGE, NULL, NL);
}

void	args_validation(int ac, char **av)
{
	argc_validation(ac);
	argv_validation(*(av + 1));
}
