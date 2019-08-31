/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrole_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:00:05 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/31 14:16:13 by rrhaenys         ###   ########.fr       */
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
	if (delta_mouse.y > 0)
		*ptr += 1;
	else if (delta_mouse.y < 0)
		*ptr -= 1;
	if (*ptr < 0)
		*ptr = 0;
	if (*ptr > len - 1)
		*ptr = len - 1;
	if (len == 0)
		*ptr = 0;
}
