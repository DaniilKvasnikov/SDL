/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_mouse_fun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:31:03 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/11 19:00:33 by rrhaenys         ###   ########.fr       */
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
	}
}