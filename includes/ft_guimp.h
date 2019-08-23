/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_guimp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:09:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:38:37 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GUIMP_H
# define FT_GUIMP_H

# include "ft_sdl.h"


t_win			*create_main(t_mydata *mydata, char *name);
t_win			*create_info_win(t_mydata *mydata, char *name);
t_win			*create_ptool_win(t_mydata *mydata, char *name);
t_element		*active_elem(void *ptr_win, t_element *elem);
int				gr_cheacker(struct s_group_e *group, void *elem);
void			ft_button_press(void *mydata, t_win *win, SDL_Event *ev);
void			main_close(t_win *win);
int				button_render(void *win, t_element *elem);
int				text_render(void *win, t_element *elem);
int				image_render(void *win, t_element *elem);
int				textline_input(void *win, t_element *elem, char *char_input);
int				textline_input_num(void *win, t_element *elem, char *char_input);
t_element		*void_touch(void *win, t_element *elem, SDL_Event *ev, t_point_int *mouse);

#endif
