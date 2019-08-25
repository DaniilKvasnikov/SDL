/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_guimp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:09:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 20:59:19 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GUIMP_H
# define FT_GUIMP_H

# include "ft_sdl.h"

void			init_main_win(char *name);
void			init_info_win(char *name);
void			main_win_fun(t_win *win, SDL_Event *ev);
void			info_win_fun(t_win *win, SDL_Event *ev);

t_element		*set_drawtype_point(t_element *elem, SDL_Event *ev);
t_element		*set_drawtype_eraser(t_element *elem, SDL_Event *ev);
t_element		*set_drawtype_line(t_element *elem, SDL_Event *ev);
t_element		*set_drawtype_rect(t_element *elem, SDL_Event *ev);
t_element		*set_drawtype_rectfilled(t_element *elem, SDL_Event *ev);
t_element		*set_active_btn_figs(t_element *elem, SDL_Event *ev);
t_element		*unset_drawtype(t_element *elem, t_element *new);

#endif
