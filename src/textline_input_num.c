/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textline_input_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:01:32 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 14:12:18 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

int
	textline_input_num(void *win, void *ptr_but, char *char_input)
{
	t_element	*but;
	int			new_int;
	char		*old_str;
	char		*str;

	but = (t_element *)ptr_but;
	old_str = ft_strdup(but->str);
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
	new_int = ft_atol(but->str);
	if (new_int >= 0 && new_int <= INT_MAX)
	{
		*but->int_par = new_int;
		free(old_str);
	}
	else
	{
		str = but->str;
		but->str = old_str;
		free(str);
	}
	return (0);
}
