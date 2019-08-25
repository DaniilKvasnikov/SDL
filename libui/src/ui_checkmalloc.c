/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_checkmalloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:05:09 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 17:57:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	*ui_checkmalloc(void *ptr, char *err_str, int line_num, char *file_name)
{
	if (ptr != NULL)
		return ptr;
	ui_fotal_error(err_str, "memory error", line_num, file_name);
	return (NULL);
}
