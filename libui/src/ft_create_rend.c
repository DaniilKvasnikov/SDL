/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_rend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:59:14 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 12:02:06 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

SDL_Renderer
	*ft_create_rend(SDL_Window *win)
{
	SDL_Renderer	*ren;
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL)
	{
		ft_printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
		exit(1);
	}
	return (ren);
}
