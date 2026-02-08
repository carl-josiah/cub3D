/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_direction_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:17:15 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/31 10:11:04 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cleanup.h>

void	throw_direction_error(t_tex_mask mask)
{
	if (!(mask & TEX_NO))
		exit_error(MISSING_NO, NULL, NL);
	if (!(mask & TEX_SO))
		exit_error(MISSING_SO, NULL, NL);
	if (!(mask & TEX_EA))
		exit_error(MISSING_EA, NULL, NL);
	if (!(mask & TEX_WE))
		exit_error(MISSING_WE, NULL, NL);
}
