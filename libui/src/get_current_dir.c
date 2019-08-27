/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:48:02 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/27 16:48:18 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

char
	*get_current_dir(void)
{
	char *cwd;

	cwd = (char *)ui_checkmalloc(malloc(sizeof(char) * (PATH_MAX + 1)), "curr dir", __LINE__, __FILE__);
	if (getcwd(cwd, PATH_MAX) != NULL)
		return (cwd);
	return (NULL);
}
