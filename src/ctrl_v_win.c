/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_v_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 04:12:01 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/18 04:18:05 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ctrl_v_win(void *ptr_win, SDL_Event *ev)
{
	t_win		*win;

	win = (t_win *)ptr_win;
	if (win->tmp_element == NULL)
		return ;
	ft_putstr("ctrl_v_win\n");
	add_element_to_win(win, win->tmp_element);
}
