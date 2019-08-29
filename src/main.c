/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 10:43:55 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/29 08:37:21 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

int
	main(void)
{
	ui_init_sdl_data();

	init_main_win("Main");
	init_ptool_win("PTool");
	init_settings_win("Settings");
	init_choose_file("Files");

	// open_win_ok("Ok", "this is message!");

	run_loop();

	ui_quite();
	return (1);
}
