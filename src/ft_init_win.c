/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:38:48 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/11 18:06:51 by rrhaenys         ###   ########.fr       */
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
	win->mouse_muve = &ft_mouse_muve;
	win->buttons = NULL;
	win->buttons_count = 0;
	win->textures_count = 0;
	win->mydata = mydata;
	win->screen = SDL_GetWindowSurface(win->win);
	return (win);
}