/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corr_param_scroll.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 10:50:49 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/27 13:33:02 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*corr_param_scroll(t_element *elem, SDL_Event *ev)
{
	ft_putstr("corr_param_scroll\n");
	if (elem->win->mouse_muve.x > elem->rect.x + elem->rect.h / 4 && elem->win->mouse_muve.x < elem->rect.x + elem->rect.w - elem->rect.h / 4 &&
		elem->win->mouse_muve.y > elem->rect.y && elem->win->mouse_muve.y < elem->rect.y + elem->rect.h)
	{
		float f = (elem->win->mouse_muve.x - elem->rect.x - elem->rect.h / 4) / (float)(elem->rect.w - elem->rect.h / 2);
		float *par = get_param_by_name(elem->params, "par");
		if (par != NULL)
		{
			*par = f;
			ft_printf("p %f\n", *par);
		}
	}
	return (elem);
}
