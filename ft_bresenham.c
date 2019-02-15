#include "../includes/fdf.h"

static void	ft_change_color(t_color *color, t_fdf *d, float max)
{
	color->red -= (d->color_start.red - d->color_end.red) / max;
	color->green -= (d->color_start.green - d->color_end.green) / max;
	color->blue -= (d->color_start.blue - d->color_end.blue) / max;
}

static void	ft_draw_line(t_point *coor, t_point *d, t_point *op, t_fdf *d)
{
	int		i;
	float	err;
	t_color color;

	i = 0;
	err = d->x / 2;
	color = d->color_start;
	while (++i <= d->x)
	{
		ft_change_color(&color, d, d->x);
		coor->x += op->x;
		err += d->y;
		if (err >= d->x)
		{
			err -= d->x;
			coor->y += op->y;
		}
		ft_put_pixel_to_image(d, coor->x, coor->y, &color);
	}
}

static void	ft_draw_column(t_point *coor, t_point *d, t_point *op, t_fdf *d)
{
	int		i;
	float	err;
	t_color color;

	i = 0;
	err = d->y / 2;
	color = d->color_start;
	while (++i <= d->y)
	{
		ft_change_color(&color, d, d->y);
		coor->y += op->y;
		err += d->x;
		if (err >= d->y)
		{
			err -= d->y;
			coor->x += op->x;
		}
		ft_put_pixel_to_image(d, coor->x, coor->y, &color);
	}
}

void		ft_bresenham(t_point *begin, t_point *end, t_fdf *d)
{
	t_point	d;
	t_point	op;
	t_point	coor;

	coor.x = begin->x;
	coor.y = begin->y;
	op.x = (end->x > begin->x ? 1 : -1);
	op.y = (end->y > begin->y ? 1 : -1);
	d.x = ABS((end->x - begin->x));
	d.y = ABS((end->y - begin->y));
	ft_put_pixel_to_image(d, coor.x, coor.y, &d->color_start);
	if (d.x > d.y)
		ft_draw_line(&coor, &d, &op, d);
	else
		ft_draw_column(&coor, &d, &op, d);
}
