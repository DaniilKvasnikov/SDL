/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_checkbox_to_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:48:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 15:58:13 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*add_checkbox_to_win(t_rect rect, char *path_tex1, char *path_tex2, t_win *win,
		int (*button_pressed)(void *win, void *but, SDL_Event *ev))
{
	return (add_element_to_win(win, init_element(rect, path_tex1, path_tex2, win, NULL, button_pressed, NULL)));
}
