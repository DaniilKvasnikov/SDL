/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:56:43 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 14:45:54 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	image_draw(t_element *elem, t_win *win)
{
	t_texture	*texture;
	if (!elem->active)
		return (0);
	if ((texture = get_texture_by_name(win, elem->texture_name)) != NULL)
		texture_render(win, elem, texture->tex);
	SDL_RenderPresent( win->ren );
	return (1);
}
