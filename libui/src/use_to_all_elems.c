/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_to_all_elems.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 09:05:46 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/29 09:13:02 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	use_to_all_elems(t_win *win, void *ptr, void (*fun)(t_element *elem, void *ptr))
{
	int		i;

	i = -1;
	while (win->elements[++i] != NULL)
		fun(win->elements[i], ptr);
}
