/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:11:51 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/17 03:21:44 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SDL_H
# define FT_SDL_H

# include <SDL2/SDL.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "ft_struct.h"
int				ft_sdl_init();

t_mydata		*init_mydata(void);
SDL_Window		*ft_createwin(char *name, t_rect rect, Uint32 flags);
SDL_Renderer	*ft_create_rend(SDL_Window *win);
t_win			*ft_init_win(t_mydata *mydata, char *name, t_rect rect, Uint32 flags);
t_win			*ft_add_win(t_mydata *mydata, t_win *new_win);
void			ft_update_win_surface(t_mydata *mydata);

void			ft_delete_win(t_mydata *mydata, int id);
void			ft_destroy_win(t_win *win);
void			ft_destroy_wins(t_mydata *mydata);

t_win			*ft_get_win_from_id(t_mydata *mydata, int id);
void			ft_run_keyboard_fun(t_mydata *mydata, SDL_Event ev);

void			ft_run_mouse_fun(t_mydata *mydata,SDL_Event *ev);

void			render_wins(t_mydata *mydata);

SDL_Texture*	loadTexture(char *path, t_win *win);
void			ft_init_texture(t_win *win, char *path, t_point_int pos);

void			ft_button_press(void *mydata, void *win, SDL_Event *ev);

void			add_texture_to_win(t_win *win, char *path);
t_texture		*get_texture_to_win(t_win *win, char *path);
t_element		*add_texture_to_elem(t_element *elem, t_texture *texture_new);

t_element		*init_element(t_rect rect, char *path_tex1, char *path_tex2, t_win *win, char *str,
					t_element *(*element_touch)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
					t_element *(*element_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
					int (*keyboard_press)(void *win, void *but, SDL_Event *ev),
					int (*draw)(void *win, void *elem));
t_element		*add_element_to_win(t_win *win, t_element *element);
t_element		*init_button_to_win(t_rect rect, char *path_tex, t_win *win, char *str,
					t_element *(*button_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
					t_element *(*active_elem)(void *ptr_win, void *buf),
					int (*draw)(void *win, void *elem));
t_element		*init_image_to_win(t_rect rect, char *path_tex, t_win *win,
					int (*draw)(void *win, void *elem));
t_element		*init_checkbox_to_win(t_rect rect, char *path_tex1, char *path_tex2, t_win *win,
					t_element *(*button_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
					int (*draw)(void *win, void *elem));
t_element		*init_sliders_to_win(t_rect rect, char *path_tex1, char *path_tex2, t_win *win,
					t_element *(*element_touch)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
					t_element *(*element_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
					int (*draw)(void *win, void *elem));
t_element		*init_progressbar(t_rect rect, char *path_tex1, char *path_tex2, t_win *win,
					int (*draw)(void *win, void *elem));
t_element		*init_textline(t_rect rect, char *path_tex1, t_win *win,
					t_element *(*element_touch)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
					int (*keyboard_press)(void *win, void *but, SDL_Event *ev),
					t_element *(*active_elem)(void *ptr_win, void *buf),
					int (*draw)(void *win, void *elem));
t_element		*init_dropdownlist_to_win(t_rect rect, char *path_tex, t_win *win, char **strs, char *str,
					t_element *(*button_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
					t_element *(*active_elem)(void *ptr_win, void *buf),
					int (*draw)(void *win, void *elem),
					int (*draw_elem)(void *win, void *elem));
t_element		*init_menulist_to_win(t_rect rect, char *path_tex, t_win *win, char **strs,
					t_element *(*button_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
					t_element *(*active_elem)(void *ptr_win, void *buf),
					int (*draw)(void *win, void *elem),
					int (*draw_elem)(void *win, void *elem));

t_group_e		*add_group_e(t_group_e *group, t_element *elem,
					int (*gr_cheacker)(struct s_group_e *group, void *elem));

t_element		*active_elem(void *ptr_win, void *buf);

int				chech_input_mouse(t_element *elem, t_point_int *mouse);
void			win_press_button(t_win *win, SDL_Event *ev, int x, int y);
t_element		*element_pressed(void *win, void *but, SDL_Event *ev, t_point_int *mouse);
t_element		*sliders_pressed(void *win, void *but, SDL_Event *ev, t_point_int *mouse);
t_element		*element_touch(void *win, void *but, SDL_Event *ev, t_point_int *mouse);
t_element		*checkbox_touch(void *win, void *but, SDL_Event *ev, t_point_int *mouse);
t_element		*radiobutton_touch(void *win, void *but, SDL_Event *ev, t_point_int *mouse);
t_element		*dropdownlist_touch(void *win, void *but, SDL_Event *ev, t_point_int *mouse);
t_element		*menulist_touch(void *win, void *but, SDL_Event *ev, t_point_int *mouse);
t_element		*groupe_touch(t_element *elem, void *win, SDL_Event *ev, t_point_int *mouse);
t_element		*push_text_to_parent(void *win, void *but, SDL_Event *ev);

int				gr_cheacker(struct s_group_e *group, void *elem);

int				textline_keyboard(void *win_ptr, void *but_ptr, SDL_Event *ev);

int				texture_render(t_win *win, t_element *elem, SDL_Texture *texture);
int				texture_render_rect(t_win *win, t_element *elem, SDL_Texture *texture, SDL_Rect *dust, SDL_Rect *src);
int				render_text(t_win* win, t_element *elem, char *str);
int				button_render(void *win, void *elem);
int				checkbox_render(void *win, void *elem);
int				sliders_render(void *win, void *elem);
int				progressbar_render(void *win, void *elem);
int				dropdownlist_render(void *win, void *elem);


int				is_parent_active_elem(t_element *elem, t_element *parent);
void			ft_print_info_elem(t_element *elem);
#endif
