/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_fotal_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:00:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 11:37:55 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ui_fotal_error(char *str, char *type)
{
	ft_putstr(str);
	ft_putchar(' ');
	ft_putstr(type);
	ft_putchar('\n');
	exit (1);
}
