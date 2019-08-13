/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render_rect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:42:40 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/13 08:04:20 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	texture_render_rect(t_win *win, t_element *elem, SDL_Texture *texture, SDL_Rect *dust, SDL_Rect *src)
{
	if (texture != NULL)
		SDL_RenderCopy( win->ren, texture, dust, src );
	return (0);
}
