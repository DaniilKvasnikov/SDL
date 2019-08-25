/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init_sdl_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 10:48:05 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 13:17:54 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ui_init_sdl_data(void)
{
	if (g_sdl_data == NULL)
		g_sdl_data = (t_sdl_data *)ui_checkmalloc(malloc(sizeof(t_sdl_data)), "g_sdl_data");
	g_sdl_data->wins = (t_win **)ui_checkmalloc(malloc(sizeof(t_win *)), "sdl wins");
	g_sdl_data->wins[0] = NULL;
	g_sdl_data->color = (t_color){255, 255, 255, 255};
	g_sdl_data->color_border = (t_color){255, 255, 255, 255};
	g_sdl_data->color_back = (t_color){255, 255, 255, 255};
	g_sdl_data->color_active = (t_color){255, 255, 255, 255};
	g_sdl_data->draw_type = NO_DRAW;
	g_sdl_data->keyboardState = SDL_GetKeyboardState(NULL);
}
