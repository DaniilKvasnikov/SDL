/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_layers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:58:45 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 20:14:16 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	add_layers(t_win *win, char *name)
{
	int			count;
	int			i;
	t_layer		**layers;

	count = get_layers_count(win);
	layers = (t_layer **)ui_checkmalloc(malloc(sizeof(t_layer *) * (count + 1)), "add layer", __LINE__, __FILE__);
	i = -1;
	while (win->layers[++i] != NULL)
		layers[i] = win->layers[i];
	layers[i] = init_layer(win, name);
	layers[i + 1] = NULL;
	free(win->layers);
	win->layers = layers;
}
