/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rect_to_sdl_rect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:14:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 14:14:39 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

SDL_Rect
	t_rect_to_sdl_rect(t_rect *ptr_rect)
{
	SDL_Rect	sdl_rect;
	t_rect		rect;

	rect = *ptr_rect;
	sdl_rect = (SDL_Rect){rect.x, rect.y, rect.w, rect.h};
	return (sdl_rect);
}
