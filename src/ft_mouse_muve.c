/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_muve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:23:01 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/19 18:41:51 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_mouse_muve(void *mydata, void *win)
{
	if (SDL_GetMouseState(&((t_mydata *)mydata)->mouse.x, &((t_mydata *)mydata)->mouse.y) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		ft_printf("x=%d y=%d id=%d\n", ((t_mydata *)mydata)->mouse.x, ((t_mydata *)mydata)->mouse.y, ((t_win *)win)->window_id);
	}
}