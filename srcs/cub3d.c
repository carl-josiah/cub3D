/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carljosiah <carljosiah@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:22:36 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/08 19:07:31 by carljosiah       ###   ########.fr       */
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
		exit_error(&data, MALLOC, NULL, NL);
	parse_file(data.file.lines, &data);
	free_all(data.file.lines, &data);
	return (EXIT_SUCCESS);
}
