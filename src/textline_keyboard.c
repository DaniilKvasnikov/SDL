/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textline_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:54:25 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/13 09:22:13 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	textline_keyboard(void *win_ptr, void *but_ptr, SDL_Event *ev)
{
	t_win		*win;
	t_element	*but;
	char		*str;

	win = (t_win *)win_ptr;
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
}