/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:04:36 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/12 09:35:00 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <cleanup.h>
# include <defines.h>
# include <math.h>
# include <mlx.h>
# include <structs.h>
# include <sys/time.h>

void	open_window(t_data *data);
int		event_handlers(t_data *data);

#endif
