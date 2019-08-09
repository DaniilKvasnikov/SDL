/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_pressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:23:53 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/09 16:20:16 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	button_pressed(void *but, SDL_Event *ev)
{
	int			mx;
	int			my;
	t_point		*pos;
	t_point		*size;

	pos = &((t_button *)but)->pos;
	size = &((t_button *)but)->size;
	if (SDL_GetMouseState(&mx, &my))
	{
		if (mx >= pos->x && mx <= (pos->x + size->x)
			&& my >= pos->y && my <= (pos->y + size->y))
		{
			ft_putendl("Button presed");
			return (1);
		}
	}
	return (0);
}