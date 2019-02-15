/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlabro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:40:52 by jlabro            #+#    #+#             */
/*   Updated: 2015/12/01 17:40:54 by jlabro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_put_pixel_to_image(t_fdf *d, int x, int y, t_color *color)
{
	char	*img_ptr;
	int		sizeline;
	int		bpp;
	int		endian;
	int		res;

	if (x < 0 || y < 0 || y >= WIN_Y || x >= WIN_X)
		return ;
	img_ptr = mlx_get_data_addr(d->img, &bpp, &sizeline, &endian);
	res = (x * (bpp / 8) + (y * sizeline));
	img_ptr[res] = color->blue * 255;
	img_ptr[res + 1] = color->green * 255;
	img_ptr[res + 2] = color->red * 255;
}
