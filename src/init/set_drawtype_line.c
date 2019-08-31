/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_drawtype_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 15:57:37 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:43:42 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*set_drawtype_line(t_element *elem, SDL_Event *ev)
{
	ft_putstr("set DRAW_LINE\n");
	elem->win->sdl_data->draw_type = DRAW_LINE;
	return (elem);
}
