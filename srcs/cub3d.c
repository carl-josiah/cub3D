/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 09:58:56 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/09 10:50:26 by ccastro          ###   ########.fr       */
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
