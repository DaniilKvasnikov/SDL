/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 08:53:33 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 08:53:57 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atol(const char *str)
{
	long long	res;
	int			par;
	int			index;

	res = 0;
	par = 1;
	index = 0;
	while (str[index] == '\n' || str[index] == '\t' || str[index] == '\r' ||
			str[index] == '\v' || str[index] == '\f' || str[index] == ' ')
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			par = -1;
		index++;
	}
	while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10 + (str[index++] - '0');
		if (res < 0)
		{
			return (-((par + 1) / 2));
		}
	}
	return (((int)res) * par);
}
