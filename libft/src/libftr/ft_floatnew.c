/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:23:26 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 15:24:12 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		*ft_floatnew(float num)
{
	float	*res;

	if ((res = (float *)malloc(sizeof(float))) == NULL)
		return (NULL);
	*res = num;
	return (res);
}
