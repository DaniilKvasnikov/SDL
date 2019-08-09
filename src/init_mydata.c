/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mydata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:56:35 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/09 16:58:02 by rrhaenys         ###   ########.fr       */
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
	return (mydata);
}