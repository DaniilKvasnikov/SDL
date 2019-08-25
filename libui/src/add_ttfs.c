/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ttfs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:09:06 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 17:21:16 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	add_ttfs(char *path, char *name, int size)
{
	int			count;
	int			i;
	t_ttf		**ttfs;

	if (fined_ttf(name))
		ui_fotal_error(name, "ttf duplicate");
	count = ui_ttf_count();
	ttfs = (t_ttf **)ui_checkmalloc(malloc(sizeof(t_ttf *) * (count + 1)), "add new ttf");
	i = -1;
	while (g_sdl_data->ttfs[++i] != NULL)
		ttfs[i] = g_sdl_data->ttfs[i];
	ttfs[i] = init_ttf(path, name, size);
	ttfs[i + 1] = NULL;
	free(g_sdl_data->ttfs);
	g_sdl_data->ttfs = ttfs;
}
