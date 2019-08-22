/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:02:32 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 14:13:13 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intnew(int num)
{
	int	*res;

	if ((res = (int *)malloc(sizeof(int))) == NULL)
		return (NULL);
	*res = num;
	return (res);
}
