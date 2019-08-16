/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_texture_to_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:42:41 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 08:35:47 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*add_texture_to_elem(t_element *elem, t_texture *texture_new)
{
	t_texture	*textures;
	int			i;

	if ((textures = (t_texture *)malloc(sizeof(t_texture) * (elem->textures_count + 1))) == NULL)
		exit(0);
	i = -1;
	while (++i < elem->textures_count)
		textures[i] = elem->textures[i];
	textures[i] = *texture_new;
	elem->textures_count++;
	if (elem->textures_count > 1)
		free(elem->textures);
	elem->textures = textures;
	return (elem);
}