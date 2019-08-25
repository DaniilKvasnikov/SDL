/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_layers_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:53:58 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 20:19:29 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	get_layers_count(t_win *win)
{
	int	i;

	i = -1;
	while (win->layers[++i] != NULL)
		;
	return (i + 1);
}
