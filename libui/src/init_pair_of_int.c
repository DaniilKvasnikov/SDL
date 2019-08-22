/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pair_of_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:59:53 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 12:20:16 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_pair_of_int
	init_pair_of_int(int *from, int *to, int one_way)
{
	*to = *from;
	return ((t_pair_of_int){from, *from, to, *to, one_way});
}
