/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 03:07:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 20:27:58 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*active_elem(t_win *win, t_element *elem)
{
	win->active_element = elem;
	return (elem);
}