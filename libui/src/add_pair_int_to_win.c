/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pair_int_to_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:28:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 12:18:55 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	add_pair_int_to_win(t_win *win, t_pair_of_int pair)
{
	t_pair_of_int	*pairs;
	int				i;

	pairs= (t_pair_of_int *)malloc(sizeof (t_pair_of_int) * (win->pairs_int.count + 1));
	i = -1;
	while (++i < win->pairs_int.count)
		pairs[i] = win->pairs_int.pairs[i];
	pairs[i] = pair;
	if (win->pairs_int.count > 0)
		free(win->pairs_int.pairs);
	win->pairs_int.pairs = pairs;
	win->pairs_int.count++;
}
