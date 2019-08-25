/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_drawtype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 20:58:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 21:05:53 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*unset_drawtype(t_element *elem, t_element *new)
{
	int	i;

	i = -1;
	while (elem->params[++i])
		((t_element *)elem->params[i]->par)->active = 0;
	return (elem);
}
