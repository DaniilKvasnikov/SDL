/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgba_int_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:50:24 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 15:52:27 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_rgba_int
	*ft_rgba_int_new(t_rgba_int elem)
{
	t_rgba_int *ptr;

	ptr = (t_rgba_int *)malloc(sizeof(t_rgba_int));
	if (ptr == NULL)
		return (ptr);
	*ptr = elem;
	return (ptr);
}
