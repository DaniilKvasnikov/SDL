/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_fotal_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:00:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 17:54:38 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ui_fotal_error(char *str, char *type, int line_num, char *file_name)
{
	ft_putstr(str);
	ft_putchar(' ');
	ft_putstr(type);
	ft_printf("line %d str=\"%s\"\n", line_num, file_name);
	ft_putchar('\n');
	exit (1);
}
