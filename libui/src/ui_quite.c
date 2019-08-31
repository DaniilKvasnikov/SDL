/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_quite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 10:48:20 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:28:54 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ui_quite(t_sdl_data *data)
{
	int	i;

	i = -1;
	while (data->wins[++i] != NULL)
		destroy_win(data->wins[i]);
	free_if_not_null(data->wins);
	free_if_not_null(data);
}
