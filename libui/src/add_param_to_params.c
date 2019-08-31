/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_param_to_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:18:09 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 12:25:19 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_param
	**add_param_to_params(t_param **params, char *name, void *param)
{
	int			count;
	int			i;
	t_param		**n_params;

	if (fined_param_by_name(params, name))
		ui_fotal_error(name, "param duplicate", __LINE__, __FILE__);
	count = ui_params_in_elem(params);
	n_params = (t_param **)ui_checkmalloc(malloc(sizeof(t_param *) * (count + 1)), "add param", __LINE__, __FILE__);
	i = -1;
	while (params[++i] != NULL)
		n_params[i] = params[i];
	n_params[i] = init_param(name, param);
	n_params[i + 1] = NULL;
	return (n_params);
}
