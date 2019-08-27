/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:51:14 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/27 16:51:28 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	get_count_file_in_dir(char *path)
{
	DIR				*d;
	struct dirent	*dir;
	int				count;

	d = opendir(path);
	count = 0;
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
			count++;
		closedir(d);
	}
	return (count);
}

char
	**get_files(char *path)
{
	DIR				*d;
	struct dirent	*dir;
	int				count;
	int				i;

	d = opendir(path);
	count = get_count_file_in_dir(path);
	ft_printf("count %d\n", count);
	char	**strs;
	strs = (char **)ui_checkmalloc(malloc(sizeof(char *) * (count + 1)), "strs", __LINE__, __FILE__);
	if (d)
	{
		i = -1;
		while ((dir = readdir(d)) != NULL)
			strs[++i] = ft_strdup(dir->d_name);
		strs[++i] = NULL;
		closedir(d);
	}
	return (strs);
}
