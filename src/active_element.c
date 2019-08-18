/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 03:07:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/18 20:10:49 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*active_elem(void *ptr_win, void *buf)
{
	((t_win *)ptr_win)->active_element = (t_element *)buf;
	return ((t_element *)buf);
}