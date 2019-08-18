/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createwins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:16:14 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/09 16:46:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

SDL_Window
	*ft_createwin(char *name, t_rect rect, Uint32 flags)
{
	SDL_Window	*win;

	win = SDL_CreateWindow(name, rect.x, rect.y, rect.w, rect.h, flags);
	if (win == NULL) {
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		return (NULL);
	}
	return (win);
}