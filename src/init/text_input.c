/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 09:17:20 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/09/04 09:22:35 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	text_input(t_element *elem, SDL_Event *ev)
{
	char		*str;
	t_element	*text;
	
	text = get_param_by_name(elem->params, "text");
	if (ev->type == SDL_TEXTINPUT && text != NULL)
	{
		str = ft_strnew(sizeof(char) * (ft_strlen(text->str) + 1));
		ft_strcpy(str, text->str);
		str[ft_strlen(str)] = ev->text.text[0];
		long long tmp = ft_atol(str);
		ft_printf("tmp %lld\n", tmp);
		if (tmp >=0 && tmp <= INT_MAX)
		{
			free(text->str);
			text->str = str;
		}
	}
	else if (ev->type == SDL_KEYDOWN && text != NULL &&
				ev->key.keysym.scancode == SDL_SCANCODE_BACKSPACE)
	{
		if (ft_strlen(text->str) > 0)
			text->str[ft_strlen(text->str) - 1] = '\0';
		str = ft_strdup(text->str);
		free(text->str);
		text->str = str;
	}
	return (0);
}
