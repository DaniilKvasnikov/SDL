/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_muve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:23:01 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/20 12:58:37 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_mouse_muve(void *mydata, void *win, SDL_Event *ev)
{
	int	x;
	int	y;

	if (ev->type == SDL_MOUSEBUTTONDOWN)
		ft_printf("%d mouse down\n", ((t_win *)win)->window_id);
	if (SDL_GetMouseState(&((t_mydata *)mydata)->mouse.x, &((t_mydata *)mydata)->mouse.y) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		SDL_SetRenderDrawColor(((t_win *)win)->ren, 255, 0, 0, 255);
		x = ((t_mydata *)mydata)->mouse.x;
		y = ((t_mydata *)mydata)->mouse.y;
		SDL_RenderDrawPoint(((t_win *)win)->ren, x, y);
		// ft_printf("x=%d y=%d id=%d\n", x, y, ((t_win *)win)->window_id);
		SDL_RenderPresent(((t_win *)win)->ren);
	} else if (SDL_GetMouseState(&((t_mydata *)mydata)->mouse.x, &((t_mydata *)mydata)->mouse.y) & SDL_BUTTON(SDL_BUTTON_RIGHT))
	{
		ft_init_texture((t_win *)win, "./img/cat.bmp", ((t_mydata *)mydata)->mouse);
	}
}