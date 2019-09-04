/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_drawtype_text.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:04:30 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 15:05:40 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_guimp.h"

t_element
	*set_drawtype_text(t_element *elem, SDL_Event *ev)
{
	ft_putstr("set DRAW_TEXT\n");
	elem->win->sdl_data->draw_type = DRAW_TEXT;
	return (elem);
}
