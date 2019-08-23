/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:50:24 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 15:52:27 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_rgb
	*ft_rgb_new(t_rgb elem)
{
	t_rgb *ptr;

	ptr = (t_rgb *)malloc(sizeof(t_rgb));
	if (ptr == NULL)
		return (ptr);
	*ptr = elem;
	return (ptr);
}
