/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:53:28 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 14:45:40 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>

typedef struct	s_point
{
	float		x;
	float		y;
}				t_point;

typedef struct	s_rect
{
	int			x;
	int			y;
	int			w;
	int			h;
}				t_rect;

typedef struct	s_point_int
{
	int			x;
	int			y;
}				t_point_int;

typedef struct	s_texture
{
	SDL_Texture	*tex;
	char		*name;
}				t_texture;

typedef struct	s_element
{
	t_point		pos;
	t_point		size;
	SDL_Texture	*texture1;
	SDL_Texture	*texture2;
	int			num_tex;
	char		*str;
	int			(*element_touch)(void *win, void *but, SDL_Event *ev);
	int			(*element_pressed)(void *win, void *but, SDL_Event *ev);
}				t_element;

typedef struct	s_win
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	int				window_id;
	void			(*button_press)(void *mydata, void *win, SDL_Event *ev);
	t_element		**elements;
	int				element_count;
	t_element		*active_element;
	t_texture		*textures;
	int				textures_count;
	void			*mydata;
}				t_win;

typedef struct	s_mydata
{
	t_win			**wins;
	int				win_count;
	const Uint8		*keyboardState;
	t_point_int		mouse;
	TTF_Font		*font;
}				t_mydata;

#endif
