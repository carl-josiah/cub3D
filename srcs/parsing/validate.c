/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:24:54 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/23 15:36:21 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

static void	argc_validation(int ac)
{
	if (ac != 2)
		exit_error(ERROR, NULL);
}

static void	argv_validation(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isspace(arg[i]))
			exit_error(ERROR, NULL);
		i++;
	}
	if (i < 5)
		exit_error(ERROR, NULL);
	i -= 4;
	if (ft_strncmp(".cub", &arg[i], 4))
		exit_error(ERROR, NULL);
}

void	args_validation(int ac, char **av)
{
	argc_validation(ac);
	argv_validation(*(av + 1));
}
