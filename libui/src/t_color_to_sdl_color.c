/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color_to_sdl_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:55:30 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 17:05:17 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

SDL_Color
	t_color_to_sdl_color(t_color *color)
{
	SDL_Color sdl_color;

	sdl_color = (SDL_Color){color->r, color->g, color->b, color->a};
	return (sdl_color);
}
