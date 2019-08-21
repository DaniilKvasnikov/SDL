/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_group_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 08:43:30 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/21 18:02:39 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_group_e
	*add_group_e(t_group_e *group, t_element *elem,
				int (*gr_cheacker)(struct s_group_e *group, void *elem))
{
	int			i;
	t_element	**group_e;

	if (group == NULL)
	{
		if ((group = (t_group_e *)malloc(sizeof(t_group_e))) == NULL)
			exit(0);
		group->count = 0;
		group->gr_cheacker = NULL;
	}
	if ((group_e = (t_element **)malloc(sizeof(t_element) * (group->count + 1))) == NULL)
		exit(0);
	i = -1;
	while (++i < group->count)
		group_e[i] = group->elements[i];
	group_e[i] = elem;
	group->count++;
	if (group->count > 1)
		free(group->elements);
	group->elements = (void **)group_e;
	if (gr_cheacker != NULL)
		group->gr_cheacker = gr_cheacker;
	return (group);
}
