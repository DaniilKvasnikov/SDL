/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_guimp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:09:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/18 21:25:10 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GUIMP_H
# define FT_GUIMP_H

# include "ft_sdl.h"


t_win			*create_main(t_mydata *mydata, char *name);
t_win			*create_info_win(t_mydata *mydata, char *name);
t_win			*create_ptool_win(t_mydata *mydata, char *name);
t_element		*active_elem(void *ptr_win, void *buf);
int				gr_cheacker(struct s_group_e *group, void *elem);
void			ft_button_press(void *mydata, void *win, SDL_Event *ev);
void			main_close(t_win *win);

#endif
