/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createwins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:16:14 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/19 16:03:21 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

SDL_Window
	*ft_createwin(char *name, t_point pos, t_point size, Uint32 flags)
{
	SDL_Window	*win;

	win = SDL_CreateWindow(name, pos.x, pos.y, size.x, size.y, flags);
	if (win == NULL) {
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		return (NULL);
	}
	return (win);
}