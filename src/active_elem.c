/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 03:07:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:19:10 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*active_elem(void *ptr_win, t_element *elem)
{
	((t_win *)ptr_win)->active_element = elem;
	return (elem);
}