/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_groupe_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 11:59:15 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 14:25:46 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	images_groupe_draw(t_element *elem, t_win *win)
{
	t_texture	*texture;
	int			i;
		int size = 50;
	if (*elem->active == 0)
		return (0);
	int	*start = get_param_by_name(elem->params, "num");
	i = *start - 1;
	char	**strs = get_param_by_name(elem->params, "strs");
	if (ft_strsplit_len(strs) == 0)
		return (1);
	int		max_elems = elem->rect.h / size;
	while (strs[++i] != NULL && i < *start + max_elems)
	{
		int	count = elem->rect.h / size;
		texture = get_texture_by_name(elem->win, strs[i]);
		if (texture != NULL)
			texture_render_by_rect(win, (t_rect){elem->rect.x, elem->rect.y + size * (i - *start), elem->rect.w, size}, texture->tex);
	}
	return (1);
}
