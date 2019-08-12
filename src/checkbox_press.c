/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:51:39 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 09:55:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	checkbox_press(void *win, void *but, SDL_Event *ev)
{
	t_element	*elem;

	elem = (t_element *)but;
	if (elem->num_tex == 0)
		elem->num_tex = 1;
	else if (elem->num_tex == 1)
		elem->num_tex = 0;
	ft_putendl("Checkbox presed");
}
