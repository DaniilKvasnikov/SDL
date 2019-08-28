/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:51:04 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/28 08:38:37 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	files_draw(t_element *elem, t_win *win)
{
	t_texture	*texture;
	int			i;
	int			j;
	char	**strs = get_param_by_name(elem->params, "strs");
	int			len_full = ft_strsplit_len(strs);
	if (elem->active == 0 || strs == NULL)
		return (0);
	if ((texture = get_texture_by_name(win, elem->texture_name)) != NULL)
	{
		int size = 50;
		int	count = elem->rect.h / size;
		i = -1;
		int *ptr_num = (int *)get_param_by_name(elem->params, "num");
		j = *ptr_num;
		while (++i <= count && strs[j] != NULL)
		{
			texture_render_by_rect(win, (t_rect){elem->rect.x, elem->rect.y + size * i, elem->rect.w, size},
			texture->tex);
			text_render_full(win,
			(t_rect){elem->rect.x, elem->rect.y + size * i, elem->rect.w, size},
			strs[j], *elem->ttf, (t_color){0, 0, 255, 255});
			j++;
		}
		texture_render_by_rect(win, (t_rect){elem->rect.x + elem->rect.w, (*ptr_num - 1) / (float)len_full * 50 * count, 25, 50}, texture->tex);
	}
	i = -1;
	while (elem->draw_sub_groupe[++i])
		if (elem->draw_sub_groupe[i]->draw)
			elem->draw_sub_groupe[i]->draw(elem->draw_sub_groupe[i], win);
	i = -1;
	while (elem->sub_groupe[++i])
		if (elem->sub_groupe[i]->active && elem->sub_groupe[i]->draw)
			elem->sub_groupe[i]->draw(elem->sub_groupe[i], win);
	return (1);
}
