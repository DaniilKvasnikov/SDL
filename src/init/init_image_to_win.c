/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_image_to_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 08:59:19 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 08:37:28 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_image_to_win(t_rect rect, char *path_tex, t_win *win,
						int (*draw)(void *win, void *elem))
{
	return (init_element(rect, path_tex, NULL, win, NULL, NULL, NULL, NULL, draw));
}
