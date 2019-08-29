/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radio_buton_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 08:55:38 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/29 09:14:04 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

static void
	deactive_all_tag(t_element *elem, void *str)
{
	char		*tag;
	int			*status;

	tag = get_param_by_name(elem->params, "tag");
	status = get_param_by_name(elem->params, "status");
	if (tag != NULL && status != NULL && ft_strcmp(tag, str) == 0)
		*status = 0;
}

t_element
	*radio_buton_down(t_element *elem, SDL_Event *ev)
{
	ft_printf("radio_buton_down\n");
	int			*status;
	int			*tag;

	status = get_param_by_name(elem->params, "status");
	tag = get_param_by_name(elem->params, "tag");
	if (status != NULL)
	{
		use_to_all_elems(elem->win, tag, &deactive_all_tag);
		if (*status == 0)
			*status = 1;
	}
	return (elem);
}
