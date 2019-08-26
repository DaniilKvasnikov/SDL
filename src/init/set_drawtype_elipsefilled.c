/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_drawtype_spherefilled.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:37:25 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 12:38:33 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*set_drawtype_elipsefilled(t_element *elem, SDL_Event *ev)
{
	ft_putstr("set DRAW_RECT_FILLED\n");
	g_sdl_data->draw_type = DRAW_ELIPSE_FILLED;
	return (elem);
}
