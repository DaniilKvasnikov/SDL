/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:38:48 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/19 12:57:23 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_win
	*ft_init_win(char *name, t_point pos, t_point size, Uint32 flags)
{
	t_win *win;

	win = (t_win *)malloc(sizeof(t_win));
	if ((win->win = ft_createwin(name, pos, size, flags)) == NULL)
		return (NULL);
	if ((win->ren = ft_create_rend(win->win)) == NULL)
		return (NULL);
	return (win);
}