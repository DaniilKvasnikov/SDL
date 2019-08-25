/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:11:51 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/25 15:04:50 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SDL_H
# define FT_SDL_H

# include <SDL2/SDL.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "ft_struct.h"
# include <math.h>

t_sdl_data	*g_sdl_data;

void				ui_init_sdl_data(void);
t_win				*ui_init_win(char *name, t_rect rect, Uint32 flags,
						void (*win_fun)(t_win *win, SDL_Event *ev));
void				ui_quite(void);
void				ui_fotal_error(char *str, char *type);
void				*ui_checkmalloc(void *ptr, char *err_str);
void				free_if_not_null(void *ptr);
SDL_Window			*ft_create_win(char *name, t_rect rect, Uint32 flags);
SDL_Renderer		*ft_create_rend(SDL_Window *win);
t_win				*ui_add_win(t_win *win);
t_element			*add_element_to_win(t_win *win, t_element *elem);
int					ui_wins_count(void);
int					ui_element_count(t_win *win);
int					ui_textures_count(t_win *win);
void				run_loop(void);
t_win				*get_active_win(SDL_Event *event);
int					is_event_close_win(SDL_Event *event);
int					touch_esc(SDL_Event *event);

int					fined_win_by_name(char *name);
int					fined_element_by_name(t_win *win, char *name);
int					fined_texture_by_name(t_win *win, char *name);
t_texture			*get_texture_by_name(t_win *win, char *texture_name);

SDL_Texture*		loadTexture(t_win *win, char *path);
t_texture			*init_texture_to_win(t_win *win, char *path_texture, char *name);
void				add_texture_to_win(t_win *win, char *path_texture, char *name);

void				mousebuttonmove_win(t_win *win, SDL_Event *event);
void				mousebuttondown_win(t_win *win, SDL_Event *event);
void				mousebuttonup_win(t_win *win, SDL_Event *event);


t_element			*ui_init_element(int active, char *name, t_rect rect, t_win *win, char *texture_name,
						t_element *parent, t_color *color, char *str, t_ttf *ttf,
						int (*draw)(t_element *elem, t_win *win),
						t_element *(*mouse_down)(t_element *elem, SDL_Event *ev),
					t_element *(*mouse_move)(t_element *elem, SDL_Event *ev),
						t_element *(*mouse_up)(t_element *elem, SDL_Event *ev),
						int (*keyboard_down)(t_element *elem, SDL_Event *ev),
						t_element *(*active_other)(t_element *elem));

void				draw_wins(void);
int					image_draw(t_element *elem, t_win *win);
int					texture_render(t_win *win, t_element *elem, SDL_Texture *texture);
int					texture_render_rect(t_win *win, SDL_Texture *texture, SDL_Rect *dust, SDL_Rect *src, SDL_RendererFlip flip);
void				ft_update_win_surface(void);

void				destroy_win(t_win *win);
void				destroy_element(t_element *elem);
void				destroy_layer(t_layer *layer);
void				destroy_texture(t_texture *texture);

int					chech_input_mouse(t_element *elem, t_point *mouse);
SDL_RendererFlip	flip_t_rect(t_rect *rect);
SDL_Rect			t_rect_to_sdl_rect(t_rect *ptr_rect);

#endif
