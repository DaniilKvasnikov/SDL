/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:11:51 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/19 18:38:29 by gamerd           ###   ########.fr       */
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

typedef struct	s_point_int
{
	int			x;
	int			y;
}				t_point_int;

typedef struct	s_win
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	int				window_id;
	void			(*button_press)(void *mydata, void *win);
	void			(*mouse_muve)(void *mydata, void *win);
}				t_win;

typedef struct	s_mydata
{
	t_win			**wins;
	int				win_count;
	SDL_Surface		*bmp;
	SDL_Texture		*tex;
	const Uint8		*keyboardState;
	t_point_int		mouse;
}				t_mydata;

int		ft_sdl_init();

SDL_Window		*ft_createwin(char *name, t_point pos, t_point size, Uint32 flags);
SDL_Renderer	*ft_create_rend(SDL_Window *win);
t_win			*ft_init_win(char *name, t_point pos, t_point size, Uint32 flags);
void			ft_add_win(t_mydata *mydata, t_win *new_win);
void			ft_update_win_surface(t_mydata *mydata);

void			ft_delete_win(t_mydata *mydata, int id);
void			ft_destroy_win(t_win *win);
void			ft_destroy_wins(t_mydata *mydata);

t_win			*ft_get_win_from_id(t_mydata *mydata, int id);
void			ft_run_keyboard_fun(t_mydata *mydata, SDL_Event ev);

void			ft_run_mouse_fun(t_mydata *mydata,SDL_Event ev);

void			ft_button_press(void *mydata, void *win);
void			ft_mouse_muve(void *mydata, void *win);
#endif
