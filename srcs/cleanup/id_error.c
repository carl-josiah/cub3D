/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:09:37 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/11 17:41:15 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cleanup.h>

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
