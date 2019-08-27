/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrole_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:00:05 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/27 17:06:15 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	scrole_files(t_win *win, t_point delta_mouse)
{
	t_element	*elem;
	int		*ptr;
	char	**strs;
	int		len;

	elem = get_element_by_name(win, "file");
	strs = get_param_by_name(elem->params, "strs");
	len = ft_strsplit_len(strs);
	ptr = get_param_by_name(elem->params, "num");
	if (delta_mouse.y > 0 && win->win_rect.w > 1 && win->win_rect.h > 1)
		*ptr += 1;
	else if (delta_mouse.y < 0 && win->win_rect.w < win->full.w * 4 && win->win_rect.h < win->full.h * 4)
		*ptr -= 1;
	if (*ptr < 1)
		*ptr = 1;
	if (*ptr > len - 1)
		*ptr = len - 1;
}
