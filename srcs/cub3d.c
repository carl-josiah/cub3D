/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carljosiah <carljosiah@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:22:36 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/11 17:55:27 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int ac, char **av)
{
	t_data	data;
	size_t	line_count;

	args_validation(ac, av);
	init_data(&data);
	data.file.lines = read_cub_file(av[1], &line_count);
	if (!data.file.lines)
		exit_error(NULL, MALLOC, NULL, NL);
	parse_file(data.file.lines, &data);
	print_grid(&data);
	free_all(data.file.lines, &data);
	return (EXIT_SUCCESS);
}
