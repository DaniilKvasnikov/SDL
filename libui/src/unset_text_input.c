/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_text_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 09:51:17 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/09/17 09:08:24 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*unset_text_input(t_element *elem, t_element *new)
{
	if (elem != new)
	{
		ft_putstr("unset_text_input\n");
		SDL_SetRenderTarget(elem->win->ren, elem->win->layers[0]->texture);
		elem->rect = (t_rect){
			(elem->rect.x - elem->win->win_rect.x) / elem->win->scale,
			(elem->rect.y - elem->win->win_rect.y) / elem->win->scale,
			elem->win->scale, elem->win->scale};
		elem->draw(elem, elem->win);
		SDL_SetRenderTarget(elem->win->ren, NULL);
		delete_elem_by_name(elem->win, elem->name);
		return (NULL);
	}
	return (elem);
}
