/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:53:28 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 10:53:39 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

# include <SDL2/SDL.h>

#ifdef __APPLE__
# include <SDL_ttf.h>
# include <SDL_image.h>
#endif
#ifdef __linux__
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_image.h>
#endif

# define BMP 1
# define PNG 2
# define JPG 3

# define NO_DRAW 0
# define DRAW_LINE 1
# define DRAW_RECT 2
# define DRAW_RECT_FILLED 3
# define DRAW_ELIPSE 4
# define DRAW_ELIPSE_FILLED 5
# define DRAW_POINT 6
# define DRAW_ERASER 7
# define DRAW_TEXTURE 8

typedef struct	s_element t_element;
typedef struct	s_sdl_data	t_sdl_data;
typedef struct	s_win t_win;
typedef struct	s_group_e t_group_e;

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
	int			type;
}				t_texture;

typedef struct	s_ttf
{
	TTF_Font	*font;
	char		*path;
	char		*name;
	int			size;
}				t_ttf;

typedef struct	s_layer
{
	SDL_Texture		*texture;
	char			*name;
}				t_layer;

typedef struct	s_param
{
	void		*par;
	char		*name;
}				t_param;

struct	s_element
{
	int					*active;
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
	char				*texture_name;
	int					(*draw)(t_element *elem, t_win *win);
	t_element			*(*mouse_down)(t_element *elem, SDL_Event *ev);
	t_element			*(*mouse_move)(t_element *elem, SDL_Event *ev);
	t_element			*(*mouse_up)(t_element *elem, SDL_Event *ev);
	int					(*keyboard_down)(t_element *elem, SDL_Event *ev);
	t_element			*(*active_other)(t_element *elem, t_element *new);
};

struct	s_win
{
	t_sdl_data		*sdl_data;
	SDL_Window		*win;
	SDL_Renderer	*ren;
	char			*name;
	t_rect			full;
	t_rect			win_rect;
	float			scale;
	int				id;
	t_element		**elements;
	t_element		*active_elem;
	t_layer			**layers;
	t_layer			*cur_layer;
	t_texture		**textures;
	t_texture		*cur_texture;
	t_rect			curr_rect;
	t_point			mouse_down;
	t_point			mouse_muve;
	void			(*mouse_muve_left)(t_win *win, t_point delta_mouse);
	void			(*mouse_muve_scrole)(t_win *win, t_point delta_mouse);
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
	t_ttf			**ttfs;
	int				line_width;
	int				draw_type;
	int				drawing;
};

#endif
