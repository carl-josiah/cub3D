/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:29:45 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/12 16:30:50 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

void	free_all(char **lines, t_data *data)
{
	free_double_ptr(lines);
	free_textures(&data->tex);
	free_map(data);
	free_mlx(data);
}
