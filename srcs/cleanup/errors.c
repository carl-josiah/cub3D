/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:25:08 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/23 16:06:21 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cleanup.h>

void	exit_error(char *msg, void **ptr) 
{
	if (ptr && *ptr)
		ft_free_ptr(ptr);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(1);
}
