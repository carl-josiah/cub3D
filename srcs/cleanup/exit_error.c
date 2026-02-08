/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:25:08 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/01 15:59:04 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cleanup.h>

void	exit_error(char *msg, char *specific, int newline)
{
	if (!msg)
		ft_putstr_fd(ERROR_NO_MSG, STDERR_FILENO);
	else
	{
		if (msg)
		{
			ft_putstr_fd(ERROR_WITH_MSG, STDERR_FILENO);
			ft_putstr_fd(msg, STDERR_FILENO);
		}
		if (specific)
		{
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putstr_fd(specific, STDERR_FILENO);
		}
	}
	if (newline)
		ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
