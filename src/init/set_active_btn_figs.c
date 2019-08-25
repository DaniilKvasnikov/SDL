/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_active_btn_figs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:00:30 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 16:39:35 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*set_active_btn_figs(t_element *elem, SDL_Event *ev)
{
	t_element *elem_gr;
	ft_putstr("set_active_btn_figs\n");
	elem_gr = get_element_by_name(elem->win, "button5");
	elem_gr->active = !elem_gr->active;
	ft_printf("%d\n", elem_gr->active);
	return (elem);
}
