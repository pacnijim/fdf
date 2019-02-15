/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlabro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:40:04 by jlabro            #+#    #+#             */
/*   Updated: 2015/12/01 17:40:09 by jlabro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_get_color(t_color *color, float red, float green, float blue)
{
	color->red = red;
	color->green = green;
	color->blue = blue;
}

void		ft_init_color(t_color *color, float depth)
{
	if (depth == 0)
		ft_get_color(color, 0, 0.7, 0);
	else if (depth < 0 && depth >= -10)
		ft_get_color(color, 0.3, 0.8, 0.8);
	else if (depth < -10)
		ft_get_color(color, 0, 0, 1);
	else if (depth > 0 && depth < 10)
		ft_get_color(color, 0.42, 0.33, 0);
	else
		ft_get_color(color, 1, 1, 1);
}
