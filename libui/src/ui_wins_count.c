/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_wins_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:17:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:32:07 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	ui_wins_count(t_sdl_data *data)
{
	int	i;

	i = -1;
	while (data->wins[++i] != NULL)
		;
	return (i + 1);
}
