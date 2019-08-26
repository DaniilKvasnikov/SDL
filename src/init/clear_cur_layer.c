/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cur_layer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:40:42 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 13:47:23 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*clear_cur_layer(t_element *elem, SDL_Event *ev)
{
	ft_putstr("clear layer\n");
	clear_layer(elem->win, 0);
	return (elem);
}
