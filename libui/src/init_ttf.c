/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ttf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:10:47 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 17:34:46 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_ttf
	*init_ttf(char *path, char *name, int size)
{
	t_ttf	*ttf;

	ttf = (t_ttf *)ui_checkmalloc(malloc(sizeof(t_ttf)), "init ttf");
	ttf->name = name;
	ttf->path = path;
	ttf->size = size;
	TTF_Init();
	ttf->font = TTF_OpenFont(path, size);
	if(ttf->font == NULL)
	{
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		exit(1);
	}
	return (ttf);
}
