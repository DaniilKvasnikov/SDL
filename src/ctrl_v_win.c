/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_v_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 04:12:01 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:43:40 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	ctrl_v_win(t_win *win, SDL_Event *ev)
{
	if (win->tmp_element == NULL)
		return ;
	ft_putstr("ctrl_v_win\n");
	if (win->active_element && win->active_element->deactive_elem)
		win->active_element->deactive_elem(win, win->active_element);
	win->active_element = add_element_to_win(win, init_element_copy(win->tmp_element));
}
