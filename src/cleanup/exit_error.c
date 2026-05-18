/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:25:08 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/12 16:23:16 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

static void	with_message(char *msg, char *specific)
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

void	exit_error(t_data *data, char *msg, char *line, int nl)
{
	if (!msg)
		ft_putstr_fd(ERROR_NO_MSG, STDERR_FILENO);
	else
		with_message(msg, line);
	if (nl)
		ft_putstr_fd("\n", STDERR_FILENO);
	if (data)
		free_all(data->file.lines, data);
	exit(EXIT_FAILURE);
}
