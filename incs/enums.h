/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:20:02 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/08 14:47:26 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_tex_mask
{
	TEX_NO = 1 << 0,
	TEX_SO = 1 << 1,
	TEX_EA = 1 << 2,
	TEX_WE = 1 << 3,
	TEX_F = 1 << 4,
	TEX_C = 1 << 5,
	TEX_DIR = TEX_NO | TEX_SO | TEX_EA | TEX_WE,
	TEX_COLOR = TEX_F | TEX_C,
	TEX_ALL = TEX_DIR | TEX_COLOR
}	t_tex_mask;

typedef enum e_state
{
	STATE_CONFIG = 1,
	STATE_MAP = 2
}	t_state;

typedef enum e_tex_status
{
	TEX_VALID = 1,
	TEX_INVALID = 2,
	TEX_DUPLICATE = 3,
	TEX_MAP = 4,
	TEX_SPACES = 5
}	t_tex_status;

#endif
