/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 10:43:55 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 18:57:41 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

int
	main(void)
{
	ui_init_sdl_data();

	init_main_win("Main");
	init_info_win("PTool");

	run_loop();

	ui_quite();
	return (1);
}
