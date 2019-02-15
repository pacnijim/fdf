#include "../includes/fdf.h"

static void	coor_ortho(t_point current, t_point *point, t_fdf *d)
{
	float	half_width;
	float	half_height;

	half_width = WIN_X / 4 + d->move_h;
	half_height = WIN_Y / 4 + d->move_v;
	current.x = current.x * d->zoom + half_width;
	current.y = current.y * d->zoom + half_height;
	current.z = current.z * d->zoom / 10;
	point->x = current.x;
	point->y = current.y;
}

static void	coor_para(t_point current, t_point *point, t_fdf *d)
{
	float	half_width;
	float	half_height;

	half_width = WIN_X / 4 + d->move_h;
	half_height = WIN_Y / 4 + d->move_v;
	current.x = current.x * d->zoom + half_width;
	current.y = current.y * d->zoom + half_height;
	current.z = current.z * d->zoom / 10;
	point->x = current.x + sin(80 * M_PI / 180) * current.z;
	point->y = current.y + cos(80 * M_PI / 180) / 2 * current.z;
}

static void	coor_iso(t_point current, t_point *point, t_fdf *d)
{
	float	half_width;
	float	half_height;

	half_width = WIN_X + d->move_h;
	half_height = -WIN_Y / 8 + d->move_v;
	current.x = current.x * d->zoom + half_width;
	current.y = current.y * d->zoom + half_height;
	current.z = current.z * d->zoom / 10;
	point->x = (current.x * sin(30 * M_PI / 180))
	- (current.y * cos(30 * M_PI / 180));
	point->y = -current.z + (current.x * sin(30 * M_PI / 180) / 2)
	+ (current.y * cos(30 * M_PI / 180) / 2);
}

static void	get_coor(t_point current, t_point *point, t_fdf *d)
{
	if (d->proj == 1)
		coor_ortho(current, point, d);
	else if (d->proj == 2)
		coor_para(current, point, d);
	else
		coor_iso(current, point, d);
}

void		ft_draw(t_fdf *d)
{
	t_point		begin;
	t_point		end;
	int			pos;

	pos = -1;
	while (++pos < d->map_size)
	{
		get_coor(d->map[pos], &begin, d);
		ft_init_color(&d->color_start, d->map[pos].z);
		if (pos >= 0 && (pos + 1) % (int)d->max.x != 0)
		{
			ft_init_color(&d->color_end, d->map[pos + 1].z);
			get_coor(d->map[pos + 1], &end, d);
			ft_bresenham(&begin, &end, d);
		}
		if (pos >= 0 && pos + (int)d->max.x < d->map_size)
		{
			ft_init_color(&d->color_end,
			d->map[pos + (int)d->max.x].z);
			get_coor(d->map[pos + (int)d->max.x], &end, d);
			ft_bresenham(&begin, &end, d);
		}
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}
