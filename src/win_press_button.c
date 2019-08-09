/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_press_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:20:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/09 16:26:39 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	win_press_button(t_win *win, SDL_Event *ev)
{
	int	i;

	i = -1;
	while (++i < win->buttons_count)
	{
		if (win->buttons[i]->button_pressed(win, win->buttons[i], ev) == 1)
			return ;
	}
}