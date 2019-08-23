/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textline_input_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:01:32 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:20:57 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

int
	textline_input_num(void *win, t_element *elem, char *char_input)
{
	int			new_int;
	char		*old_str;
	char		*str;

	old_str = ft_strdup(elem->str);
	if (char_input[0] == 8)
	{
		if (ft_strlen(elem->str) > 0)
			elem->str[ft_strlen(elem->str) - 1] = '\0';
	}
	else if (elem->str == NULL && char_input[0] >= '0' && char_input[0] <= '9')
	{
		elem->str = ft_strnew(2);
		elem->str[0] = char_input[0];
	}
	else if (char_input[0] >= '0' && char_input[0] <= '9')
	{
		str = ft_strnew(ft_strlen(elem->str) + 2);
		ft_strcpy(str, elem->str);
		str[ft_strlen(str)] = char_input[0];
		free(elem->str);
		elem->str = str;
	}
	new_int = ft_atol(elem->str);
	if (new_int >= 0 && new_int <= INT_MAX)
	{
		*elem->int_par = new_int;
		free(old_str);
	}
	else
	{
		str = elem->str;
		elem->str = old_str;
		free(str);
	}
	return (0);
}
