/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:55:51 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 11:57:30 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

SDL_Window
	*ft_create_win(char *name, t_rect rect, Uint32 flags)
{
	SDL_Window	*win;

	win = SDL_CreateWindow(name, rect.x, rect.y, rect.w, rect.h, flags);
	if (win == NULL)
	{
		ft_printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
		exit(1);
	}
	return (win);
}
