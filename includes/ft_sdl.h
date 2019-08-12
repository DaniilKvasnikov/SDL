/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:11:51 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/12 20:18:34 by rrhaenys         ###   ########.fr       */
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
void			ft_add_win(t_mydata *mydata, t_win *new_win);
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

t_element		*init_element(t_rect rect, char *path_tex1, char *path_tex2, t_win *win, char *str,
					int (*element_touch)(void *win, void *but, SDL_Event *ev),
					int (*element_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
					int (*draw)(void *win, void *elem));
t_element		*add_element_to_win(t_win *win, t_element *element);
t_element		*add_button_to_win(t_rect rect, char *path_tex, t_win *win, char *str,
					int (*button_pressed)(void *win, void *but, SDL_Event *ev),
					int (*draw)(void *win, void *elem));
t_element		*add_image_to_win(t_rect rect, char *path_tex, t_win *win,
					int (*draw)(void *win, void *elem));
t_element		*add_checkbox_to_win(t_rect rect, char *path_tex1, char *path_tex2, t_win *win,
					int (*button_pressed)(void *win, void *but, SDL_Event *ev),
					int (*draw)(void *win, void *elem));
t_element
				*add_sliders_to_win(t_rect rect, char *path_tex1, char *path_tex2, t_win *win,
					int (*element_touch)(void *win, void *but, SDL_Event *ev),
					int (*element_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
					int (*draw)(void *win, void *elem));

void			win_press_button(t_win *win, SDL_Event *ev, int x, int y);
int				element_pressed(void *win, void *but, SDL_Event *ev, t_point_int *mouse);
int				sliders_pressed(void *win, void *but, SDL_Event *ev, t_point_int *mouse);
int				element_touch(void *win, void *but, SDL_Event *ev);
int				checkbox_touch(void *win, void *but, SDL_Event *ev);


int				texture_render(t_win *win, t_element *elem, SDL_Texture *texture);
int				texture_render_rect(t_win *win, t_element *elem, SDL_Texture *texture, SDL_Rect *rect);
int				render_text(t_win* win, t_element *elem, char *str);
int				button_render(void *win, void *elem);
int				checkbox_render(void *win, void *elem);
int				sliders_render(void *win, void *elem);
#endif
