/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:53:28 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/24 14:57:06 by rrhaenys         ###   ########.fr       */
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

# define NO_DRAW 0
# define DRAW_LINE 1
# define DRAW_RECT 2
# define DRAW_RECT_FILLED 3
# define DRAW_ELIPSE 4
# define DRAW_ELIPSE_FILLED 5
# define DRAW_POINT 6
# define DRAW_ERASER 7

typedef struct	s_element t_element;
typedef struct	s_win t_win;
typedef struct	s_mydata t_mydata;
typedef struct	s_group_e t_group_e;

typedef struct	s_point
{
	float		x;
	float		y;
}				t_point;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_rgb;

typedef struct	s_point_int
{
	int			x;
	int			y;
}				t_point_int;

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
	char		*name;
}				t_texture;

struct	s_group_e
{
	t_element	**elements;
	int			count;
	int			(*gr_cheacker)(t_group_e *group, t_element *elem);
};

struct	s_element
{
	t_rect				rect;
	t_texture			*textures;
	int					textures_count;
	int					*int_par;
	float				*float_par;
	char				*str;
	t_group_e			*sub_group;
	t_element			*parent;
	t_point_int			last_delta;
	int					type;
	t_rgb				*color;
	t_rgb				*color_border;
	int					(*draw)(t_win *win, t_element *elem);
	t_element			*(*element_touch)(t_win *win, t_element *elem, SDL_Event *ev, t_point_int *mouse);
	t_element			*(*element_pressed)(t_win *win, t_element *elem, SDL_Event *ev, t_point_int *mouse);
	int					(*keyboard_press)(t_win *win, t_element *elem, char *char_input);
	t_element			*(*deactive_elem)(t_win *win, t_element *elem);
	t_element			*(*active_elem)(t_win *win, t_element *elem);
};

typedef struct	s_pair_of_int
{
	int			*ptr_from;
	int			old_from;
	int			*ptr_to;
	int			old_to;
	int			one_way;
}				t_pair_of_int;

typedef struct	s_pairs_int
{
	t_pair_of_int	*pairs;
	int				count;
}				t_pairs_int;

typedef struct	s_layers
{
	SDL_Texture		**textures;
	int				count;
}				t_layers;

struct	s_win
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	int				window_id;
	t_element		**elements;
	int				element_count;
	t_element		*active_element;
	t_element		*tmp_element;
	t_texture		*textures;
	int				textures_count;
	t_mydata		*mydata;
	t_group_e		*groupe;
	t_layers		layers;
	t_pairs_int		pairs_int;
	t_point_int		lst_mouse;
	t_point_int		cur_mouse;
	void			(*button_press)(t_mydata *mydata, t_win *win, SDL_Event *ev);
	void			(*ctrl_c)(t_win *win, SDL_Event *ev);
	void			(*ctrl_v)(t_win *win, SDL_Event *ev);
	void			(*fun_close)(t_win *win);
};

struct	s_mydata
{
	t_win			**wins;
	int				win_count;
	const Uint8		*keyboardState;
	t_point_int		mouse;
	TTF_Font		*font;
	int				ctrl_c;
	int				ctrl_v;
	t_rgb			back_color;
	t_rgb			color;
	t_rgb			color_border;
	t_rgb			active_border;
	t_rgb			*curr_color;
	int				draw_type;
};

#endif
