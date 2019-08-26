/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_save_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:58:52 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 15:14:22 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_guimp.h"

t_element
	*btn_save_file(t_element *elem, SDL_Event *ev)
{
	ft_putstr("save file\n");
	save_file(elem->win, BMP, 0, "save.bmp");
	return (elem);
}
