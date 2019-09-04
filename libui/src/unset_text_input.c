/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_text_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 09:51:17 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/09/04 10:06:23 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*unset_text_input(t_element *elem, t_element *new)
{
	if (elem != new)
	{
		ft_putstr("unset_text_input\n");
		delete_elem_by_name(elem->win, elem->name);
		return (NULL);
	}
	return (elem);
}
