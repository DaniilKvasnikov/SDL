/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textline_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:54:25 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/13 09:05:06 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	textline_keyboard(void *win_ptr, void *but_ptr, SDL_Event *ev)
{
	t_win		*win;
	t_element	*but;

	win = (t_win *)win_ptr;
	but = (t_element *)but_ptr;
	if(ev->type == SDL_TEXTINPUT)
	{
		ft_printf("input : %c\n", ev->text.text);
	}
}