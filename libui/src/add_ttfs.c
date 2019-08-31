/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ttfs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:09:06 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:30:53 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	add_ttfs(t_sdl_data *data, char *path, char *name, int size)
{
	int			count;
	int			i;
	t_ttf		**ttfs;

	if (fined_ttf(data, name))
		ui_fotal_error(name, "ttf duplicate", __LINE__, __FILE__);
	count = ui_ttf_count(data);
	ttfs = (t_ttf **)ui_checkmalloc(malloc(sizeof(t_ttf *) * (count + 1)), "add new ttf", __LINE__, __FILE__);
	i = -1;
	while (data->ttfs[++i] != NULL)
		ttfs[i] = data->ttfs[i];
	ttfs[i] = init_ttf(path, name, size);
	ttfs[i + 1] = NULL;
	free(data->ttfs);
	data->ttfs = ttfs;
}
