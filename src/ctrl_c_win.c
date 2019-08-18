/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_c_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 04:04:47 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/18 20:10:40 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	ctrl_c_win(void *ptr_win, SDL_Event *ev)
{
	t_win		*win;
	t_element	*new_elem;

	win = (t_win *)ptr_win;
	if (win->active_element == NULL)
		return ;
	ft_putstr("ctrl_c_win\n");
	new_elem = init_element_copy(win->active_element);
	if (win->tmp_element != NULL)
		free(win->tmp_element);
	win->tmp_element = new_elem;
}
