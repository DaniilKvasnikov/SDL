/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_progressbar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:58:47 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 20:33:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_progressbar(t_rect rect, char *path_tex1, char *path_tex2, t_win *win, int *int_par, float *float_par,
		int (*draw)(t_win *win, t_element *elem))
{
	return (init_element(rect, path_tex1, path_tex2, win, NULL, int_par, float_par, NULL, NULL, NULL, draw));
}
