/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_guimp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:09:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/27 13:40:16 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GUIMP_H
# define FT_GUIMP_H

# include "ft_sdl.h"

void			init_main_win(char *name);
void			init_ptool_win(char *name);
void			init_settings_win(char *name);
void			init_images_win(char *name);
void			init_choose_file(char *name);
void			main_mouse_muve_left(t_win *win, t_point delta_mouse);
void			mouse_muve_scrole(t_win *win, t_point delta_mouse);
int				input_border_size(t_element *elem, SDL_Event *ev);
void			info_win_fun(t_win *win, t_point delta_mouse);

t_element		*set_drawtype_point(t_element *elem, SDL_Event *ev);
t_element		*set_drawtype_nodraw(t_element *elem, SDL_Event *ev);
t_element		*set_drawtype_eraser(t_element *elem, SDL_Event *ev);
t_element		*set_drawtype_line(t_element *elem, SDL_Event *ev);
t_element		*set_drawtype_rect(t_element *elem, SDL_Event *ev);
t_element		*set_drawtype_rectfilled(t_element *elem, SDL_Event *ev);
t_element		*set_drawtype_texture(t_element *elem, SDL_Event *ev);
t_element		*set_drawtype_elipsefilled(t_element *elem, SDL_Event *ev);
t_element		*clear_cur_layer(t_element *elem, SDL_Event *ev);
t_element		*btn_save_file(t_element *elem, SDL_Event *ev);
t_element		*btn_open_file_dialog_img(t_element *elem, SDL_Event *ev);
t_element		*set_drawtype_elipse(t_element *elem, SDL_Event *ev);
t_element		*set_active_btn_figs(t_element *elem, SDL_Event *ev);
t_element		*unset_drawtype(t_element *elem, t_element *new);

#endif
