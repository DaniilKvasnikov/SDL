/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_params_in_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:41:26 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 18:41:44 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	ui_params_in_elem(t_element *elem)
{
	int	i;

	i = -1;
	while (elem->params[++i] != NULL)
		;
	return (i + 1);
}
