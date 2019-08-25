/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousebuttonmove_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:09:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 19:07:10 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	mousebuttonmove_win(t_win *win, SDL_Event *event)
{
	if (event->button.button == SDL_BUTTON_LEFT)
		win->mouse_muve = g_sdl_data->mouse;
}
