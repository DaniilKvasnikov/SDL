/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 08:46:57 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/27 08:55:01 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	init_images_win(char *name)
{
	t_win		*win;
	t_element	*button;
	t_element	*elem;
	t_element	*text;

	ui_add_win(win = ui_init_win(ft_strdup(name), (t_rect){100, 700, 1040, 200},
		SDL_WINDOW_SHOWN, NULL, NULL));
}
