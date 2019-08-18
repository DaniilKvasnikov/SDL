/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:38:48 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/18 04:16:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_win
	*ft_init_win(t_mydata *mydata, char *name, t_rect rect, Uint32 flags)
{
	t_win *win;

	win = (t_win *)malloc(sizeof(t_win));
	if ((win->win = ft_createwin(name, rect, flags)) == NULL)
		return (NULL);
	if ((win->ren = ft_create_rend(win->win)) == NULL)
		return (NULL);
	win->window_id = SDL_GetWindowID(win->win);
	win->button_press = &ft_button_press;
	win->elements = NULL;
	win->element_count = 0;
	win->textures_count = 0;
	win->active_element = NULL;
	win->mydata = mydata;
	win->groupe = NULL;
	win->layers.count = 1;
	win->layers.textures = (SDL_Texture **)malloc(sizeof(SDL_Texture *));
	if (win->layers.textures == NULL)
		exit (0);
	win->layers.textures[0] = SDL_CreateTexture(win->ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
	if (win->layers.textures[0] == NULL)
		exit (0);
	win->ctrl_c = NULL;
	win->ctrl_v = NULL;
	win->tmp_element = NULL;
	return (win);
}