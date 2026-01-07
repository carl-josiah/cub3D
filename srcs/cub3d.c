/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carljosiah <carljosiah@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:22:36 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/08 01:01:03 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "parsing.h"
#include "structs.h"
#include <cub3d.h>

int	main(int ac, char **av)
{
	char	*line;
	int		fd;
	t_data	data;

	// if (DEBUG_MAIN)
	// {
	// 	(void)fd;
	// 	(void)data;
	// 	print_for_me("maps/map.cub");
	// }
	args_validation(ac, av);
	init_data(&data);
	// if (DEBUG_MAIN)
	// {
	// 	fd = open(av[1], O_RDONLY);
	// 	line = get_next_line(fd);
	// 	while (line)
	// 	{
	// 		parse_texture(line, &data.tex);
	// 		free(line);
	// 		line = get_next_line(fd);
	// 	}
	// }
	if (DEBUG_MAIN)
	{
		line = NULL;
		(void)fd;
		store_map_line(&data.map, line);
	}
	return (EXIT_SUCCESS);
}
