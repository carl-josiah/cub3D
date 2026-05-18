/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:04:42 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/24 12:53:46 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

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

void	throw_color_error(t_data *data)
{
	if (!((data->tex.mask & TEX_F) & TEX_F))
		exit_error(data, MISSING_F, NULL, NL);
	if (!((data->tex.mask & TEX_C) & TEX_C))
		exit_error(data, MISSING_C, NULL, NL);
}

void	throw_id_error(int id, t_data *data)
{
	if (id == -1)
		exit_error(data, "Invalid texture identifier", NULL, NL);
	else if (id == 0)
		return ;
	else if ((id & data->tex.mask) && id & TEX_DIR)
		exit_error(data, "Duplicate texture identifier", NULL, NL);
	else if ((id & data->tex.mask) && id & TEX_COLOR)
		exit_error(data, "Duplicate color identifier", NULL, NL);
}
