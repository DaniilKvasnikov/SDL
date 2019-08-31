/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_esc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:14:52 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:26:41 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	touch_esc(t_sdl_data *data, SDL_Event *event)
{
	return (data->keyboardState[SDL_SCANCODE_ESCAPE]);
}
