/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:19:07 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/27 17:18:48 by ilyabaturin      ###   ########.fr       */
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
	int	cur = g_sdl_data->mouse.y / size + num;
	char	**strs = get_param_by_name(elem->params, "strs");
	int		len_strs = ft_strsplit_len(strs);
	ft_printf("cur %d\n", cur);
	if (cur < len_strs)
	{
		char	*old_path = get_current_dir();
		chdir(strs[cur]);
		char	*new_path = get_current_dir();
		char	**n_strs = get_files(new_path);
		set_param_by_name(elem->params, "strs", n_strs);
		if (ft_strcmp(old_path, new_path) != 0)
			*ptr_num = 1;
		free(old_path);
		free(new_path);
	}
	return (elem);
}
