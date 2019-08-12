/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_mouse_fun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:31:03 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/12 14:58:42 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_run_mouse_fun(t_mydata *mydata,SDL_Event *ev)
{
	t_win 	*win;
	int		x;
	int		y;

	win = ft_get_win_from_id(mydata, ev->window.windowID);
	if (win == NULL)
		return ;
	if (SDL_GetMouseState(&x, &y))
	{
		if (ev->type == SDL_MOUSEBUTTONDOWN)
			win_press_button(win, ev, x, y);
		if (ev->type == SDL_MOUSEBUTTONUP)
			win->active_element = NULL;
		if (win->active_element != NULL
			&& win->active_element->element_pressed != NULL)
			win->active_element->element_pressed(win, win->active_element, ev);
	}
}