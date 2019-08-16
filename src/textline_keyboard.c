/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textline_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:54:25 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 08:42:43 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	textline_keyboard(void *win_ptr, void *but_ptr, SDL_Event *ev)
{
	t_element	*but;
	char		*str;

	but = (t_element *)but_ptr;
	if(ev->type == SDL_TEXTINPUT && ft_strlen(ev->text.text) == 1)
	{
		if (but->str == NULL)
		{
			but->str = ft_strnew(2);
			but->str[0] = ev->text.text[0];
		}
		else
		{
			str = ft_strnew(ft_strlen(but->str) + 2);
			ft_strcpy(str, but->str);
			str[ft_strlen(str)] = ev->text.text[0];
			free(but->str);
			but->str = str;
		}
	}
	else if (ev->key.keysym.scancode == SDL_SCANCODE_BACKSPACE)
	{
		if (ft_strlen(but->str) > 0)
			but->str[ft_strlen(but->str) - 1] = '\0';
		// ft_printf("len = %d %s\n", ft_strlen(ev->text.text), SDL_GetScancodeName(ev->key.keysym.scancode));
	}
	else if (ev->key.keysym.scancode == SDL_SCANCODE_RETURN)
	{
		if (but->str == NULL)
		{
			but->str = ft_strnew(2);
			but->str[0] = '\n';
		}
		else
		{
			str = ft_strnew(ft_strlen(but->str) + 2);
			ft_strcpy(str, but->str);
			str[ft_strlen(str)] = '\n';
			free(but->str);
			but->str = str;
		}
	}
	return (0);
}