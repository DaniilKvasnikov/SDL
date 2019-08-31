/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:19:07 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/31 11:38:34 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*files_down(t_element *elem, SDL_Event *ev)
{
	t_element	*elem_gr;
	int			i;
	int size = 50;
	int	count = elem->rect.h / size;
	int *ptr_num = (int *)get_param_by_name(elem->params, "num");
	int num = *ptr_num;
	int	cur = elem->win->sdl_data->mouse.y / size + num;
	char	**strs = get_param_by_name(elem->params, "strs");
	int		len_strs = ft_strsplit_len(strs);
	ft_printf("cur %d\n", cur);
	if (cur <= len_strs)
	{
		char	*old_path = get_current_dir();
		char	*path_text = ft_stradd_3(old_path, "/", strs[cur]);
		t_win	*main = get_win_by_name(elem->win->sdl_data, "Main");
		chdir(strs[cur]);
		char	*new_path = get_current_dir();
		char	**n_strs = get_files(new_path);
		set_param_by_name(elem->params, "strs", n_strs);
		if (ft_strcmp(old_path, new_path) != 0)
			*ptr_num = 1;
		else
		{
			t_texture	*texture;
			if ((texture = get_texture_by_path(main, path_text)) == NULL)
			{
				int	type = 0;
				if (ft_strcmp(path_text + ft_strlen(path_text) - 4, ".bmp") == 0)
					type = BMP;
				else if (ft_strcmp(path_text + ft_strlen(path_text) - 4, ".jpg") == 0)
					type = JPG;
				else if (ft_strcmp(path_text + ft_strlen(path_text) - 4, ".png") == 0)
					type = PNG;
				t_texture *texture_but = init_texture_to_win(main, path_text, path_text, type);
				texture = add_texture_to_win(main, path_text, path_text, type);
			}
			main->cur_texture = texture;
			elem->win->sdl_data->draw_type = DRAW_TEXTURE;
		}
		free(old_path);
		free(new_path);
	}
	return (elem);
}
