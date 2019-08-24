/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:53:28 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/24 23:16:36 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

# include <SDL2/SDL.h>

#ifdef __APPLE__
# include <SDL_ttf.h>
#endif
#ifdef __linux__
# include <SDL2/SDL_ttf.h>
#endif

typedef struct	s_sdl_data	t_sdl_data;
typedef struct	s_element	t_element;
typedef struct	s_win		t_win;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_color;

typedef struct	s_rect
{
	int			x;
	int			y;
	int			w;
	int			h;
}				t_rect;

typedef struct	s_texture
{
	SDL_Texture	*tex;
	char		*path;
	char		*name;
	t_rect		rect;
}				t_texture;

typedef struct	s_ttf
{
	TTF_Font	*font;
	char		*path;
	int			size;
}				t_ttf;

typedef struct	s_layers
{
	SDL_Texture		*texture;
	char			*name;
}				t_layers;

typedef struct	s_param
{
	void		*par;
	char		*name;
}				t_param;

struct	s_element
{
	int					active;
	char				*name;
	t_rect				rect;
	t_win				*win;
	t_point				last_delta_mouse;
	t_element			**draw_sub_groupe;
	t_element			**sub_groupe;
	t_element			*parent;
	t_color				*color;
	char				*str;
	t_ttf				*ttf;
	t_param				**params;
	int					(*draw)(t_element *elem, t_win *win);
	t_element			*(*mouse_down)(t_element *elem, SDL_Event *ev);
	t_element			*(*mouse_move)(t_element *elem, SDL_Event *ev);
	t_element			*(*mouse_up)(t_element *elem, SDL_Event *ev);
	int					(*keyboard_down)(t_element *elem, SDL_Event *ev);
	t_element			*(*active_other)(t_element *elem);
};

struct	s_win
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	char			*name;
	t_element		**elements;
	t_element		*active_elem;
	t_layers		**layers;
	t_layers		*cur_layer;
	t_texture		**textures;
	t_sdl_data		*mydata;
	t_rect			curr_rect;
	t_rect			rect;
	t_point			mouse_down;
	t_point			mouse_muve;
};

struct	s_sdl_data
{
	t_point			mouse;
	const Uint8		*keyboardState;
	t_win			**wins;
	t_color			color;
	t_color			color_border;
	t_color			color_back;
	t_color			color_active;
	int				draw_type;
};

#endif
