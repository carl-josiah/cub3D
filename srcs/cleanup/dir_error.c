/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:04:42 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/12 11:47:43 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cleanup.h>

void	throw_direction_error(t_data *data)
{
	if (!((data->tex.mask & TEX_NO) & TEX_NO))
		exit_error(data, MISSING_NO, NULL, NL);
	if (!((data->tex.mask & TEX_SO) & TEX_SO))
		exit_error(data, MISSING_SO, NULL, NL);
	if (!((data->tex.mask & TEX_EA) & TEX_EA))
		exit_error(data, MISSING_EA, NULL, NL);
	if (!((data->tex.mask & TEX_WE) & TEX_WE))
		exit_error(data, MISSING_WE, NULL, NL);
}
