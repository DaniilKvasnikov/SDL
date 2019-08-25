/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_esc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:14:52 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 13:17:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	touch_esc(SDL_Event *event)
{
	return (g_sdl_data->keyboardState[SDL_SCANCODE_ESCAPE]);
}
