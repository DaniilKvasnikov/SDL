/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textline_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:54:25 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:23:53 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	textline_keyboard(void *win_ptr, t_element *elem, SDL_Event *ev,
					int (*keyboard_press)(void *win, t_element *elem, char *char_input))
{
	char		*str;

	if(ev->type == SDL_TEXTINPUT && ft_strlen(ev->text.text) == 1)
	{
		keyboard_press((t_win *)win_ptr, elem, ev->text.text);
	}
	else if (ev->type == SDL_KEYDOWN && ev->key.keysym.scancode == SDL_SCANCODE_BACKSPACE)
	{
		str = ft_strdup(" ");
		str[0] = 8;
		keyboard_press((t_win *)win_ptr, elem, str);
		free(str);
		// ft_printf("len = %d %s\n", ft_strlen(ev->text.text), SDL_GetScancodeName(ev->key.keysym.scancode));
	}
	else if (ev->type == SDL_KEYDOWN && ev->key.keysym.scancode == SDL_SCANCODE_RETURN)
	{
		str = ft_strdup("\n");
		keyboard_press((t_win *)win_ptr, elem, str);
		free(str);
	}
	return (0);
}