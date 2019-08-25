/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_drawtype_brush.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:58:44 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 15:00:43 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*set_drawtype_brush(t_element *elem, SDL_Event *ev)
{
	ft_putstr("set DRAW_BRUSH\n");
	g_sdl_data->draw_type = DRAW_BRUSH;
	return (elem);
}