/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:01:37 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/12 11:46:09 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cleanup.h>

void	throw_color_error(t_data *data)
{
	if (!((data->tex.mask & TEX_F) & TEX_F))
		exit_error(data, MISSING_F, NULL, NL);
	if (!((data->tex.mask & TEX_C) & TEX_C))
		exit_error(data, MISSING_C, NULL, NL);
}
