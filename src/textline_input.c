/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textline_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 09:08:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 20:33:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

int
	textline_input(t_win *win, t_element *elem, char *char_input)
{
	char		*str;

	if (char_input[0] == 8)
	{
		if (ft_strlen(elem->str) > 0)
			elem->str[ft_strlen(elem->str) - 1] = '\0';
	}
	else if (elem->str == NULL)
	{
		elem->str = ft_strnew(2);
		elem->str[0] = char_input[0];
	}
	else
	{
		str = ft_strnew(ft_strlen(elem->str) + 2);
		ft_strcpy(str, elem->str);
		str[ft_strlen(str)] = char_input[0];
		free(elem->str);
		elem->str = str;
	}
	return (0);
}
