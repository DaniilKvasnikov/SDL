/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mydata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:56:35 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/11 17:59:43 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_mydata
	*init_mydata(void)
{
	t_mydata	*mydata;

	if((mydata = (t_mydata *)malloc(sizeof(t_mydata))) == NULL)
		return (mydata);
	mydata->win_count = 0;
	mydata->keyboardState = SDL_GetKeyboardState(NULL);
	TTF_Init();
	if( TTF_Init() == -1 )
	{
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(1);
	}
	mydata->font = TTF_OpenFont("/usr/share/fonts/truetype/freefont/FreeMonoOblique.ttf", 24);
	if(mydata->font == NULL)
	{
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		exit(1);
	}
	return (mydata);
}