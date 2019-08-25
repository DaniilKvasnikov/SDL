/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_quite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 10:48:20 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 12:27:41 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ui_quite(void)
{
	int	i;

	i = -1;
	while (g_sdl_data->wins[++i] != NULL)
		destroy_win(g_sdl_data->wins[i]);
	free_if_not_null(g_sdl_data->wins);
	free_if_not_null(g_sdl_data);
}
