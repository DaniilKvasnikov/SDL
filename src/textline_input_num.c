/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textline_input_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:01:32 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/21 17:05:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

int
	textline_input_num(void *win, void *ptr_but, char *char_input)
{
	t_element	*but;
	char		*str;

	but = (t_element *)ptr_but;
	if (char_input[0] == 8)
	{
		if (ft_strlen(but->str) > 0)
			but->str[ft_strlen(but->str) - 1] = '\0';
	}
	else if (but->str == NULL && char_input[0] >= '0' && char_input[0] <= '9')
	{
		but->str = ft_strnew(2);
		but->str[0] = char_input[0];
	}
	else if (char_input[0] >= '0' && char_input[0] <= '9')
	{
		str = ft_strnew(ft_strlen(but->str) + 2);
		ft_strcpy(str, but->str);
		str[ft_strlen(str)] = char_input[0];
		free(but->str);
		but->str = str;
	}
	return (0);
}
