/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_element_in_groupe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 15:32:01 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 15:32:24 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	ui_element_in_groupe(t_element **groupe)
{
	int	i;

	i = -1;
	while (groupe[++i] != NULL)
		;
	return (i + 1);
}
