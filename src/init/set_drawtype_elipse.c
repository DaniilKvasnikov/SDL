/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_drawtype_elipse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:37:09 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:36:38 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*set_drawtype_elipse(t_element *elem, SDL_Event *ev)
{
	ft_putstr("set DRAW_RECT_FILLED\n");
	elem->win->sdl_data->draw_type = DRAW_ELIPSE;
	return (elem);
}
