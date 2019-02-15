/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlabro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 13:30:05 by jlabro            #+#    #+#             */
/*   Updated: 2015/11/20 13:30:06 by jlabro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <math.h>
# define ABS(x) (x >= 0 ? x : -x)
# define MIN(x, y) (x >= y ? y : x)
# define WIN_X 2000
# define WIN_Y 1200
# define CST_1 0.65
# define CST_2 0.866
# define ESCAPE 53
# define PAGE_UP 116
# define PAGE_DOWN 121
# define LEFT  123
# define RIGHT 124
# define UP    126
# define DOWN  125
# define END   119
# define ONE   18
# define TWO   19
# define THREE 20

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
}					t_point;

typedef struct		s_color
{
	float			red;
	float			green;
	float			blue;
}					t_color;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	t_point			*map;
	t_point			max;
	int				map_size;
	t_color			color_start;
	t_color			color_end;
	int				zoom;
	int				move_h;
	int				move_v;
	t_point			depth;
	int				proj;
}					t_fdf;

void				ft_init_mlx(t_fdf *d, char *file);
void				ft_init_color(t_color *color, float depth);
void				ft_init_depth(t_fdf *d, int pos1, int pos2);
void				ft_read_file(t_fdf *d, char *file);
void				ft_draw(t_fdf *d);
void				ft_bresenham(t_point *begin, t_point *end, t_fdf *d);
void				ft_put_pixel_to_image(t_fdf *d, int x, int y,
					t_color *color);

#endif
