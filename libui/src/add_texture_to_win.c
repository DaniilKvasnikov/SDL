/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_texture_to_win.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:16:47 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 13:19:27 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_texture
	*add_texture_to_win(t_win *win, char *path_texture, char *name, int type)
{
	int			count;
	int			i;
	t_texture	**textures;

	if (fined_texture_by_name(win, name))
		ui_fotal_error(name, "texture duplicate", __LINE__, __FILE__);
	count = ui_textures_count(win);
	textures = (t_texture **)ui_checkmalloc(malloc(sizeof(t_texture *) * (count + 1)), "add new texture", __LINE__, __FILE__);
	i = -1;
	while (win->textures[++i] != NULL)
		textures[i] = win->textures[i];
	textures[i] = init_texture_to_win(win, path_texture, name, type);
	textures[i + 1] = NULL;
	free(win->textures);
	win->textures = textures;
}
