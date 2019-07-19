/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:11:51 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/19 13:05:17 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SDL_H
# define FT_SDL_H

# include <SDL2/SDL.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef struct	s_point
{
	float		x;
	float		y;
}				t_point;

typedef struct	s_win
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
}				t_win;

typedef struct	s_mydata
{
	t_win			**wins;
	int				win_count;
	SDL_Surface		*bmp;
	SDL_Texture		*tex;
}				t_mydata;

int		ft_sdl_init();

SDL_Window		*ft_createwin(char *name, t_point pos, t_point size, Uint32 flags);
SDL_Renderer	*ft_create_rend(SDL_Window *win);
t_win			*ft_init_win(char *name, t_point pos, t_point size, Uint32 flags);
void			ft_add_win(t_mydata *mydata, t_win *new_win);

#endif
