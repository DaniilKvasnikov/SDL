/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mydata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:56:35 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/24 14:49:45 by rrhaenys         ###   ########.fr       */
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
	mydata->font = TTF_OpenFont("./fonts/17710.ttf", 12);
	if(mydata->font == NULL)
	{
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		exit(1);
	}
	mydata->ctrl_c = 0;
	mydata->ctrl_v = 0;
	mydata->color = (t_rgb){255, 255, 255};
	mydata->color_border = (t_rgb){255, 255, 255};
	mydata->back_color = (t_rgb){0, 0, 0};
	mydata->active_border = (t_rgb){255, 0, 0};
	mydata->curr_color = &mydata->color;
	mydata->draw_type = NO_DRAW;
	return (mydata);
}