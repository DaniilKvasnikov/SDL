/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_drawtype_rect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:15:57 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:37:58 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*set_drawtype_rect(t_element *elem, SDL_Event *ev)
{
	ft_putstr("set DRAW_RECT\n");
	elem->win->sdl_data->draw_type = DRAW_RECT;
	return (elem);
}
