/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init_sdl_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 10:48:05 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 21:55:31 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ui_init_sdl_data(void)
{
	if (g_sdl_data == NULL)
		g_sdl_data = (t_sdl_data *)ui_checkmalloc(malloc(sizeof(t_sdl_data)), "g_sdl_data", __LINE__, __FILE__);
	g_sdl_data->wins = (t_win **)ui_checkmalloc(malloc(sizeof(t_win *)), "sdl wins", __LINE__, __FILE__);
	g_sdl_data->wins[0] = NULL;
	g_sdl_data->color = (t_color){255, 0, 0, 255};
	g_sdl_data->color_border = (t_color){0, 255, 0, 255};
	g_sdl_data->color_back = (t_color){0, 0, 0, 0};
	g_sdl_data->color_active = (t_color){255, 255, 255, 255};
	g_sdl_data->draw_type = NO_DRAW;
	g_sdl_data->keyboardState = SDL_GetKeyboardState(NULL);
	g_sdl_data->ttfs = (t_ttf **)ui_checkmalloc(malloc(sizeof(t_ttf *)), "ttfs", __LINE__, __FILE__);
	g_sdl_data->ttfs[0] = NULL;
	g_sdl_data->line_width = 1;
	g_sdl_data->drawing = 0;
	TTF_Init();
	if( TTF_Init() == -1 )
	{
		ft_printf("TTF_Init: %s\n", TTF_GetError());
		exit(1);
	}
	add_ttfs("fonts/17710.ttf", "standart", 14);
}
