/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_guimp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:09:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 15:01:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GUIMP_H
# define FT_GUIMP_H

# include "ft_sdl.h"

void			init_main_win(char *name);
void			init_info_win(char *name);
void			main_win_fun(t_win *win, SDL_Event *ev);
void			info_win_fun(t_win *win, SDL_Event *ev);

t_element		*set_drawtype_brush(t_element *elem, SDL_Event *ev);

#endif
