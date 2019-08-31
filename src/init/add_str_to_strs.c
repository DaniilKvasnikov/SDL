/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_to_strs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:49:10 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 13:07:32 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

char
	**add_str_to_strs(char **strs, char *str)
{
	char	**n_strs;
	int		count;
	int		i;

	count = ft_strsplit_len(strs);
	n_strs = (char **)ui_checkmalloc(malloc(sizeof(char *) * (count + 2)), "add to strs", __LINE__, __FILE__);
	i = -1;
	while (strs[++i] != NULL)
		n_strs[i] = strs[i];
	n_strs[i] = ft_strdup(str);
	n_strs[i + 1] = NULL;
	return (n_strs);
}
