/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_active_btn_figs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:00:30 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/29 09:20:50 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*set_active_btn_figs(t_element *elem, SDL_Event *ev)
{
	t_element	*elem_gr;
	int			i;
	ft_putstr("set_active_btn_figs\n");
	i = -1;
	while (elem->params[++i])
	{
		elem_gr = (t_element *)elem->params[i]->par;
		*elem_gr->active = !(*elem_gr->active);
	}
	ft_printf("%d\n", *elem_gr->active);
	return (elem);
}
