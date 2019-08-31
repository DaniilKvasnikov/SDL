/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_drawtype_eraser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 15:53:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:37:46 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*set_drawtype_eraser(t_element *elem, SDL_Event *ev)
{
	ft_putstr("set DRAW_ERASER\n");
	elem->win->sdl_data->draw_type = DRAW_ERASER;
	return (elem);
}
