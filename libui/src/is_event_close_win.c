/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_event_close_win.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:50:44 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 12:51:36 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	is_event_close_win(SDL_Event *event)
{
	return (event->type == SDL_WINDOWEVENT
			&& event->window.event == SDL_WINDOWEVENT_CLOSE);
}
