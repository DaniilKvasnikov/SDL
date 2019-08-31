/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 10:43:55 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:34:17 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

int
	main(void)
{
	t_sdl_data	*sdl_data = ui_init_sdl_data();
	add_ttfs(sdl_data, "fonts/17710.ttf", "standart", 14);

	init_main_win(sdl_data, "Main");
	init_ptool_win(sdl_data, "PTool");
	init_settings_win(sdl_data, "Settings");
	init_choose_file(sdl_data, "Files");

	// open_win_ok("Ok", "this is message!");

	run_loop(sdl_data);

	ui_quite(sdl_data);
	return (1);
}
