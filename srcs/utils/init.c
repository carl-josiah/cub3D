/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:10:30 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/24 11:59:20 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	init_data(t_data *data)
{
	int	i;

	init_tex(&data->tex);
	init_map(&data->map);
	init_player(&data->player);
	init_file(&data->file);
	i = 0;
	while (i < TEX_COUNT)
	{
		init_img(&data->textures[i]);
		i++;
	}
}
