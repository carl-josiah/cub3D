/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carljosiah <carljosiah@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:22:36 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/05 13:57:32 by ccastro          ###   ########.fr       */
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
		exit_error(MALLOC, NULL, NL);
	parse_file(lines, &data);
	free_double_ptr(lines);
	return (EXIT_SUCCESS);
}
