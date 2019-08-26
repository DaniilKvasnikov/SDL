/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_rect_to_t_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:18:49 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/26 18:19:34 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_point
	at_rect_to_t_point(t_rect *rect)
{
	return ((t_point){rect->x, rect->y});
}