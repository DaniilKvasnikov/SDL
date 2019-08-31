/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_param_to_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:38:45 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 12:27:16 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*add_param_to_elem(t_element *elem, char *name, void *param)
{
	int			count;
	int			i;
	t_param		**n_params;

	n_params = add_param_to_params(elem->params, name, param);
	free(elem->params);
	elem->params = n_params;
	return (elem);
}
