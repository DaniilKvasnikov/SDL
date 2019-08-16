/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_progressbar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:58:47 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 08:38:55 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*add_progressbar(t_rect rect, char *path_tex1, char *path_tex2, t_win *win,
		int (*draw)(void *win, void *elem))
{
	return (add_element_to_win(win, init_element(rect, path_tex1, path_tex2, win, NULL, NULL, NULL, NULL, draw)));
}
