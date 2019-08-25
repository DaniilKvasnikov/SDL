/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:11:51 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/25 13:25:10 by rrhaenys         ###   ########.fr       */
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

void			ui_init_sdl_data(void);
t_win			*ui_init_win(char *name, t_rect rect, Uint32 flags,
					void (*win_fun)(t_win *win, SDL_Event *ev));
void			ui_quite(void);
void			ui_fotal_error(char *str, char *type);
void			*ui_checkmalloc(void *ptr, char *err_str);
void			free_if_not_null(void *ptr);
int				fined_win_by_name(char *name);
SDL_Window		*ft_create_win(char *name, t_rect rect, Uint32 flags);
SDL_Renderer	*ft_create_rend(SDL_Window *win);
t_win			*ui_add_win(t_win *win);
int				ui_wins_count(void);
void			run_loop(void);
t_win			*get_active_win(SDL_Event *event);
int				is_event_close_win(SDL_Event *event);
int				touch_esc(SDL_Event *event);

void			mousebuttonmove_win(t_win *win, SDL_Event *event);
void			mousebuttondown_win(t_win *win, SDL_Event *event);
void			mousebuttonup_win(t_win *win, SDL_Event *event);

void			draw_wins(void);

void			destroy_win(t_win *win);
void			destroy_element(t_element *elem);
void			destroy_layer(t_layer *layer);
void			destroy_texture(t_texture *texture);

#endif
