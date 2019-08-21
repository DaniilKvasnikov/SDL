/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textline_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:54:25 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/21 10:12:48 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	textline_keyboard(void *win_ptr, void *but_ptr, SDL_Event *ev,
					int (*keyboard_press)(void *win, void *but, char *char_input))
{
	t_element	*but;
	char		*str;

	ft_putstr("textline_keyboard\n");
	but = (t_element *)but_ptr;
	if(ev->type == SDL_TEXTINPUT && ft_strlen(ev->text.text) == 1)
	{
		keyboard_press((t_win *)win_ptr, but, ev->text.text);
	}
	else if (ev->type == SDL_KEYDOWN && ev->key.keysym.scancode == SDL_SCANCODE_BACKSPACE)
	{
		str = ft_strdup(" ");
		str[0] = 8;
		keyboard_press((t_win *)win_ptr, but, str);
		free(str);
		// ft_printf("len = %d %s\n", ft_strlen(ev->text.text), SDL_GetScancodeName(ev->key.keysym.scancode));
	}
	else if (ev->type == SDL_KEYDOWN && ev->key.keysym.scancode == SDL_SCANCODE_RETURN)
	{
		str = ft_strdup("\n");
		keyboard_press((t_win *)win_ptr, but, str);
		free(str);
	}
	return (0);
}