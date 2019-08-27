/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:04:56 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/27 17:05:08 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	ft_strsplit_len(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i] != NULL)
		;
	return (i);
}
