/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_params_in_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:41:26 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 12:22:13 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	ui_params_in_elem(t_param **params)
{
	int	i;

	i = -1;
	while (params[++i] != NULL)
		;
	return (i + 1);
}
