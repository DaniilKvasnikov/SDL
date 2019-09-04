/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:11:51 by gamerd            #+#    #+#             */
/*   Updated: 2019/09/04 10:10:34 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SDL_H
# define FT_SDL_H

# include <SDL2/SDL.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "ft_struct.h"
# include <math.h>

char				*get_current_dir(void);

t_point				at_rect_to_t_point(t_rect *rect);
t_point				summ_t_point(t_point a, t_point b);
t_point				diff_t_point(t_point a, t_point b);

t_element			*empty_down(t_element *elem, SDL_Event *ev);
t_element			*radio_buton_down(t_element *elem, SDL_Event *ev);

t_sdl_data			*ui_init_sdl_data(void);
t_win				*ui_init_win(t_sdl_data *data, char *name, t_rect rect, Uint32 flags,
						void (*mouse_muve_left)(t_win *win, t_point delta_mouse),
						void (*mouse_muve_scrole)(t_win *win, t_point delta_mouse));
void				ui_quite(t_sdl_data *data);
void				ui_fotal_error(char *str, char *type, int line_num, char *file_name);
void				*ui_checkmalloc(void *ptr, char *err_str, int line_num, char *file_name);
void				free_if_not_null(void *ptr);
SDL_Window			*ft_create_win(char *name, t_rect rect, Uint32 flags);
SDL_Renderer		*ft_create_rend(SDL_Window *win);
t_win				*ui_add_win(t_win *win);
t_element			*add_element_to_win(t_win *win, t_element *elem);
void				add_ttfs(t_sdl_data *data, char *path, char *name, int size);
int					ui_wins_count(t_sdl_data *data);
int					ui_element_count(t_win *win);
int					ui_textures_count(t_win *win);
int					ui_ttf_count(t_sdl_data *data);
int					get_layers_count(t_win *win);
int					ui_params_in_elem(t_param **params);
int					ui_element_in_groupe(t_element **groupe);
void				run_loop(t_sdl_data *data);
t_win				*get_active_win(t_sdl_data *data, SDL_Event *event);
int					is_event_close_win(SDL_Event *event);
int					touch_esc(t_sdl_data *data, SDL_Event *event);
t_layer				*init_layer(t_win *win, char *name);
void				add_layers(t_win *win, char *name);

int					fined_win_by_name(t_sdl_data *data, char *name);
int					fined_element_by_name(t_win *win, char *name);
int					fined_texture_by_name(t_win *win, char *name);
int					fined_ttf(t_sdl_data *data, char *name);
int					fined_param_by_name(t_param **params, char *name);
t_ttf				*get_ttf_by_name(t_sdl_data *data, char *name, int size);
t_element			*get_element_by_name(t_win *win, char *name);
t_texture			*get_texture_by_name(t_win *win, char *texture_name);
t_texture			*get_texture_by_path(t_win *win, char *texture_path);
t_win				*get_win_by_name(t_sdl_data *data, char *name);
void				*get_param_by_name(t_param **params, char *str);
void				*set_param_by_name(t_param **params, char *str, void *new_param);
char				**get_files(char *path);
t_element			*delete_elem_by_name(t_win *win, char *name);

SDL_Texture*		loadTexture(t_win *win, char *path, int type);
int					check_texture(t_win *win, char *path, int type);
t_texture			*init_texture_to_win(t_win *win, char *path_texture, char *name, int type);
t_texture			*add_texture_to_win(t_win *win, char *path_texture, char *name, int type);
t_element			*add_element_draw_to_win(t_element *groupe, t_element *elem);
t_element			*add_element_groupe(t_element *groupe, t_element *elem);

void				mousebuttonmove_win(t_win *win, SDL_Event *event);
void				mousebuttondown_win(t_win *win, SDL_Event *event);
void				mousebuttonup_win(t_win *win, SDL_Event *event);


t_element			*ui_init_element(int *active, char *name, t_rect rect, t_win *win, char *texture_name,
						t_element *parent, t_color *color, char *str, t_ttf *ttf,
						int (*draw)(t_element *elem, t_win *win),
						t_element *(*mouse_down)(t_element *elem, SDL_Event *ev),
						t_element *(*mouse_move)(t_element *elem, SDL_Event *ev),
						t_element *(*mouse_up)(t_element *elem, SDL_Event *ev),
						int (*keyboard_down)(t_element *elem, SDL_Event *ev),
						t_element *(*active_other)(t_element *elem, t_element *new));

t_element			*files_down(t_element *elem, SDL_Event *ev);
void				clear_layer(t_win *win, int num_layer);
void				draw_wins(t_sdl_data *data);
int					image_draw(t_element *elem, t_win *win);
int					images_groupe_draw(t_element *elem, t_win *win);
int					radiobut_render(t_element *elem, t_win *win);
int					render_text(t_element *elem, t_win *win);
int					text_render_full(t_win *win, t_rect rect, char *str, t_ttf ttf, t_color color);
int					texture_render(t_win *win, t_element *elem, SDL_Texture *texture);
int					texture_render_by_rect(t_win *win, t_rect rect, SDL_Texture *texture);
int					texture_render_rect(t_win *win, SDL_Texture *texture, SDL_Rect *dust, SDL_Rect *src, SDL_RendererFlip flip);
int					open_win_ok(t_sdl_data *data, char *name, char *message);
void				cur_texture_draw(t_win *win, int num_layer);

void				ft_update_win_surface(t_sdl_data *data);

void				destroy_win(t_win *win);
void				destroy_element(t_element *elem);
void				destroy_layer(t_layer *layer);
void				destroy_texture(t_texture *texture);
void				draw_elipse(SDL_Renderer *ren, t_rect field, int full);
int					scroll_draw(t_element *elem, t_win *win);

int					chech_input_mouse(t_element *elem, t_point *mouse);
SDL_RendererFlip	flip_t_rect(t_rect *rect);
SDL_Rect			t_rect_to_sdl_rect(t_rect *ptr_rect);
SDL_Color			t_color_to_sdl_color(t_color *color);

t_ttf				*init_ttf(char *path, char *name, int size);
t_param				*init_param(char *name, void *par);
t_color				*ft_colornew(t_color tmp);
int					files_draw(t_element *elem, t_win *win);

t_element			*corr_param_scroll(t_element *elem, SDL_Event *ev);
void				ui_draw_line_width(t_win *win, int x1, int y1, int x2, int y2, int width);
void				ui_draw_point_width(t_win *win, int x1, int y1, int width);
void				draw_layers(t_win *win);
void				draw_elements(t_win *win, int type, int num_layer);
void				draw_elem_to_tex(t_win *win, int num_layer);
t_element			*add_param_to_elem(t_element *elem, char *name, void *param);
t_param				**add_param_to_params(t_param **params, char *name, void *param);
t_element			*close_cur_win(t_element *elem, SDL_Event *ev);
void				save_file(t_win *win, int type, int num_layer, char *path);

void				scrole_files(t_win *win, t_point delta_mouse);
void				scrole_images(t_win *win, t_point delta_mouse);

void				use_to_all_elems(t_win *win, void *ptr, void (*fun)(t_element *elem, void *ptr));

int					input_border_size(t_element *elem, SDL_Event *ev);
int					text_input(t_element *elem, SDL_Event *ev);
t_element			*unset_text_input(t_element *elem, t_element *new);

int					ft_strsplit_len(char **strs);
char				**add_str_to_strs(char **strs, char *str);
#endif
