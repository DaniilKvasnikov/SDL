/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:43:55 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 18:47:18 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_param
	*init_param(char *name, void *par)
{
	t_param	*param;

	param = (t_param *)ui_checkmalloc(malloc(sizeof(t_param)), "init param", __LINE__, __FILE__);
	param->name = name;
	param->par = par;
	return (param);
}
