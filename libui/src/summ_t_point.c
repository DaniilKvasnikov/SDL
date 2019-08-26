/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   summ_t_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:11:51 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/26 18:16:53 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_point
	summ_t_point(t_point a, t_point b)
{
	return ((t_point){a.x - b.x, a.y - b.y});
}
