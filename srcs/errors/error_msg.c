/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:25:08 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/02 18:30:58 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errors.h>

void	exit_error(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(2);
}

