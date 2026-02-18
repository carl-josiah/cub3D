/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carljosiah <carljosiah@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:22:36 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/18 07:41:26 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int ac, char **av)
{
	t_data	data;
	char	**lines;

	args_validation(ac, av);
	init_data(&data);
	lines = read_cub_file(av[1]);
	if (!lines)
		exit_error(NULL, MALLOC, NULL, NL);
	parse_file(lines, &data);
	free_double_ptr(lines);
	free_textures(&data.tex);
	return (EXIT_SUCCESS);
}
