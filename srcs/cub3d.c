/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carljosiah <carljosiah@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:22:36 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/11 12:53:49 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	free_all(char **lines, t_data *data)
{
	free_double_ptr(lines);
	free_textures(&data->tex);
	free_map(data);
}

int	main(int ac, char **av)
{
	t_data	data;
		char	**lines;
	size_t	line_count;

	args_validation(ac, av);
	init_data(&data);
	lines = read_cub_file(av[1], &line_count);
	if (!lines)
		exit_error(NULL, MALLOC, NULL, NL);
	parse_file(lines, &data);
	// print_grid(&data);
	free_all(lines, &data);
	return (EXIT_SUCCESS);
}
