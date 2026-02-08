/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_color_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 10:11:24 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/31 10:12:45 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cleanup.h>

void	throw_color_error(t_tex_mask mask)
{
	if (!(mask & TEX_F))
		exit_error(MISSING_F, NULL, NL);
	if (!(mask & TEX_C))
		exit_error(MISSING_C, NULL, NL);
}
