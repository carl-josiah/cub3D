/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_id_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:09:37 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/29 13:12:05 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cleanup.h>

void	throw_id_error(int id, t_tex *tex)
{
	if (id == -1)
		exit_error("Invalid texture identifier", NULL, NL);
	else if (id == 0)
		return ;
	else if (id & tex->mask && id & TEX_DIR)
		exit_error("Duplicate texture identifier", NULL, NL);
	else if (id & tex->mask && id & TEX_COLOR)
		exit_error("Duplicate color identifier", NULL, NL);
}
