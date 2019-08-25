/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_drawtype_rectfilled.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:17:07 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 16:17:20 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*set_drawtype_rectfilled(t_element *elem, SDL_Event *ev)
{
	ft_putstr("set DRAW_LINE\n");
	g_sdl_data->draw_type = DRAW_RECT_FILLED;
	return (elem);
}
