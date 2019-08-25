/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_to_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:21:11 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 14:30:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_texture
	*init_texture_to_win(t_win *win, char *path_texture, char *name)
{
	t_texture	*texture;

	texture = (t_texture *)ui_checkmalloc(malloc(sizeof(t_texture)), "texture");
	texture->path = path_texture;
	texture->tex = loadTexture(win, path_texture);
	texture->rect = (t_rect){0, 0, 0, 0};
	texture->name = name;
	SDL_QueryTexture(texture->tex, NULL, NULL, &texture->rect.w, &texture->rect.h);
	return (texture);
}
