/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:04:37 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 10:07:47 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_print_info_elem(t_element *elem)
{
	if (elem->str)
		ft_printf("str = %s ", elem->str);
	if (elem->parent && ((t_element *)elem->parent)->str)
		ft_printf("parent = %s", ((t_element *)elem->parent)->str);
	ft_putchar('\n');
}