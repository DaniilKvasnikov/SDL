/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:38:48 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/23 19:38:34 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_win
	*ft_init_win(t_mydata *mydata, char *name, t_rect rect, Uint32 flags,
		void (*button_press)(void *mydata, t_win *win, SDL_Event *ev))
{
	t_win *win;

	win = (t_win *)malloc(sizeof(t_win));
	if ((win->win = ft_createwin(name, rect, flags)) == NULL)
		return (NULL);
	if ((win->ren = ft_create_rend(win->win)) == NULL)
		return (NULL);
	win->window_id = SDL_GetWindowID(win->win);
	win->button_press = button_press;
	win->elements = NULL;
	win->element_count = 0;
	win->textures_count = 0;
	win->active_element = NULL;
	win->mydata = mydata;
	win->groupe = NULL;
	win->layers.count = 3;
	win->layers.textures = (SDL_Texture **)malloc(sizeof(SDL_Texture *) * win->layers.count);
	if (win->layers.textures == NULL)
		exit (0);
	int		i;
	i = -1;
	while (++i < win->layers.count)
	{
		win->layers.textures[i] = SDL_CreateTexture(win->ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
		if (win->layers.textures[i] == NULL)
			exit (0);
		SDL_SetRenderTarget(win->ren, win->layers.textures[i]);
		SDL_SetRenderDrawColor(win->ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear( win->ren );
	}
	SDL_SetRenderTarget(win->ren, NULL);
	win->ctrl_c = NULL;
	win->ctrl_v = NULL;
	win->tmp_element = NULL;
	win->fun_close = NULL;
	win->cur_mouse = (t_point_int){0, 0};
	win->lst_mouse = (t_point_int){0, 0};
	win->pairs_int.count = 0;
	win->pairs_int.pairs = NULL;
	return (win);
}