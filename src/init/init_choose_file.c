/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_choose_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:39:13 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/31 11:36:13 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	print_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i] != NULL)
		ft_printf("strs[%d] %s\n", i, strs[i]);
}

void
	init_choose_file(t_sdl_data *data, char *name)
{
	t_win		*win;
	t_element	*button;

	ui_add_win(win = ui_init_win(data, ft_strdup(name), (t_rect){1140, 200, 300, 480},
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &main_mouse_muve_left, &scrole_files));
	add_texture_to_win(win, "img/cat.bmp", "cat", BMP);
	add_texture_to_win(win, "img/button_1.bmp", "button1", BMP);

	button = ui_init_element(ft_intnew(1), "file", (t_rect){0, 0, win->win_rect.w - 25, win->win_rect.h}, win, "button1", NULL, NULL, NULL,
						NULL, &files_draw, &files_down, NULL, NULL, NULL, NULL);
	add_element_to_win(win, button);
	button->ttf = get_ttf_by_name(win->sdl_data, "standart", 14);
	char	*path = get_current_dir();
	char	**strs = get_files(path);
	add_param_to_elem(button, "strs", strs);
	add_param_to_elem(button, "num", ft_intnew(1));
	free(path);
}
