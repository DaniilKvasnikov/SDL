/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_drawtype_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:53:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 14:27:23 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*set_drawtype_texture(t_element *elem, SDL_Event *ev)
{
	int			i;
	int size = 50;
	int	count = elem->rect.h / size;
	int *ptr_num = (int *)get_param_by_name(elem->params, "num");
	int num = *ptr_num;
	int	cur = (elem->win->sdl_data->mouse.y - elem->rect.y) / size + num;
	char	**strs = get_param_by_name(elem->params, "strs");
	int		len_strs = ft_strsplit_len(strs);
	if (len_strs <= 0 || cur > len_strs)
		return (NULL);
	ft_printf("cur %d\n", cur);

	ft_putstr("set DRAW_TEXTURE\n");
	elem->win->sdl_data->draw_type = DRAW_TEXTURE;
	t_win		*win;
	t_texture	*texture;
	t_texture	*texture_but;
	win = get_win_by_name(elem->win->sdl_data, "Main");
	if (win != NULL)
	{
		if ((texture = get_texture_by_name(win, strs[cur])) == NULL)
		{
			texture_but = get_texture_by_name(elem->win, strs[cur]);
			texture = add_texture_to_win(win, texture_but->path, texture_but->name, texture_but->type);
		}
		win->cur_texture = texture;
	}
	return (elem);
}
