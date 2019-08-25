/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colornew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:01:50 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 17:56:03 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_color
	*ft_colornew(t_color tmp)
{
	t_color	*color;

	color =(t_color *)ui_checkmalloc(malloc(sizeof(t_color)), "color", __LINE__, __FILE__);
	*color = tmp;
	return (color);
}
