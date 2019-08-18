/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element_copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 04:08:11 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/18 04:10:55 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_element_copy(t_element *old_elem)
{
	t_element	*element;

	if ((element = (t_element *)malloc(sizeof(t_element))) == NULL)
		return NULL;
	*element = *old_elem;
	return (element);
}
