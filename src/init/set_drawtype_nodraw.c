/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_drawtype_nodraw.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:53:47 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/26 17:54:01 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*set_drawtype_nodraw(t_element *elem, SDL_Event *ev)
{
	ft_putstr("set NO_DRAW\n");
	g_sdl_data->draw_type = NO_DRAW;
	return (elem);
}
