/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:53:28 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:43:08 by rrhaenys         ###   ########.fr       */
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

typedef struct	s_group_e
{
	void		**elements;
	int			count;
	int			(*gr_cheacker)(struct s_group_e *group, void *elem);
}				t_group_e;

typedef struct	s_element
{
	t_rect				rect;
	t_texture			*textures;
	int					textures_count;
	int					*int_par;
	float				*float_par;
	char				*str;
	t_group_e			*sub_group;
	void				*parent;
	t_point_int			last_delta;
	int					type;
	t_rgb			*color;
	t_rgb			*color_border;
	int					(*draw)(void *ptr_win, struct s_element *elem);
	struct s_element	*(*element_touch)(void *ptr_win, struct s_element *elem, SDL_Event *ev, t_point_int *mouse);
	struct s_element	*(*element_pressed)(void *ptr_win, struct s_element *elem, SDL_Event *ev, t_point_int *mouse);
	int					(*keyboard_press)(void *ptr_win, struct s_element *elem, char *char_input);
	struct s_element	*(*deactive_elem)(void *ptr_win, struct s_element *elem);
	struct s_element	*(*active_elem)(void *ptr_win, struct s_element *elem);
}				t_element;

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

typedef struct	s_win
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
	void			*mydata;
	t_group_e		*groupe;
	t_layers		layers;
	t_pairs_int		pairs_int;
	t_point_int		lst_mouse;
	t_point_int		cur_mouse;
	void			(*button_press)(void *mydata, struct s_win *win, SDL_Event *ev);
	void			(*ctrl_c)(struct s_win *win, SDL_Event *ev);
	void			(*ctrl_v)(struct s_win *win, SDL_Event *ev);
	void			(*fun_close)(struct s_win *win);
}				t_win;

typedef struct	s_mydata
{
	t_win			**wins;
	int				win_count;
	const Uint8		*keyboardState;
	t_point_int		mouse;
	TTF_Font		*font;
	int				ctrl_c;
	int				ctrl_v;
	t_rgb			color;
	t_rgb			color_border;
	t_rgb			*curr_color;
}				t_mydata;

#endif
