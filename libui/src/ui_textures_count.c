/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_textures_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:18:14 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 14:18:28 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	ui_textures_count(t_win *win)
{
	int	i;

	i = -1;
	while (win->textures[++i] != NULL)
		;
	return (i + 1);
}
