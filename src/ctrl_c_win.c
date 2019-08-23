/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_c_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 04:04:47 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:44:08 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	ctrl_c_win(t_win *win, SDL_Event *ev)
{
	t_element	*new_elem;

	if (win->active_element == NULL)
		return ;
	ft_putstr("ctrl_c_win\n");
	new_elem = init_element_copy(win->active_element);
	if (win->tmp_element != NULL)
		free(win->tmp_element);
	win->tmp_element = new_elem;
}
