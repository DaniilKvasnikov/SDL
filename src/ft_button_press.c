/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:01:14 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/23 19:32:58 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_button_press(void *mydata, t_win *win, SDL_Event *ev)
{
	if (win->active_element != NULL && win->active_element->keyboard_press != NULL)
		textline_keyboard(win, win->active_element, ev, win->active_element->keyboard_press);
}