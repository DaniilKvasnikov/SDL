/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_drawtype_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:53:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:37:32 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*set_drawtype_texture(t_element *elem, SDL_Event *ev)
{
	ft_putstr("set DRAW_TEXTURE\n");
	elem->win->sdl_data->draw_type = DRAW_TEXTURE;
	t_win		*win;
	t_texture	*texture;
	t_texture	*texture_but;
	win = get_win_by_name(elem->win->sdl_data, "Main");
	if (win != NULL)
	{
		if ((texture = get_texture_by_name(win, elem->texture_name)) == NULL)
		{
			texture_but = get_texture_by_name(elem->win, elem->texture_name);
			texture = add_texture_to_win(win, texture_but->path, texture_but->name, texture_but->type);
		}
		win->cur_texture = texture;
	}
	return (elem);
}
