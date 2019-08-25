/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_param_to_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:38:45 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 18:50:04 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*add_param_to_elem(t_element *elem, char *name, void *param)
{
	int			count;
	int			i;
	t_param		**params;

	if (fined_param_by_name(elem, name))
		ui_fotal_error(name, "param duplicate", __LINE__, __FILE__);
	count = ui_params_in_elem(elem);
	params = (t_param **)ui_checkmalloc(malloc(sizeof(t_param *) * (count + 1)), "add param", __LINE__, __FILE__);
	i = -1;
	while (elem->params[++i] != NULL)
		params[i] = elem->params[i];
	params[i] = init_param(name, param);
	params[i + 1] = NULL;
	free(elem->params);
	elem->params = params;
	return (elem);
}
