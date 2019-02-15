#include "../includes/fdf.h"

static int	expose_hook(t_fdf *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->img,
	0, 0);
	return (0);
}

static void	get_key2(int keycode, t_fdf *d)
{
	if (keycode == DOWN)
		d->move_v += 20;
	else if (keycode == END || keycode == ONE || keycode == TWO
	|| keycode == THREE)
	{
		d->move_v = 0;
		d->move_h = 0;
		d->zoom = 5;
		if (keycode == ONE)
			d->proj = 1;
		else if (keycode == TWO)
			d->proj = 2;
		else if (keycode == THREE)
			d->proj = 3;
	}
}

static int	get_key(int keycode, t_fdf *d)
{
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(d->mlx, d->win);
		exit(0);
	}
	if (keycode == PAGE_DOWN || keycode == PAGE_UP || keycode == LEFT
	|| keycode == RIGHT || keycode == UP || keycode == DOWN || keycode == END
	|| keycode == ONE || keycode == TWO || keycode == THREE)
	{
		mlx_destroy_image(d->mlx, d->img);
		d->img = mlx_new_image(d->mlx, WIN_X, WIN_Y);
		if (keycode == PAGE_UP && d->zoom < 500)
			d->zoom += 5;
		else if (keycode == PAGE_DOWN && d->zoom > 5)
			d->zoom -= 5;
		else if (keycode == LEFT)
			d->move_h -= 20;
		else if (keycode == RIGHT)
			d->move_h += 20;
		else if (keycode == UP)
			d->move_v -= 20;
		get_key2(keycode, d);
		ft_draw(d);
	}
	return (0);
}

static void	ft_init_data(t_fdf *d)
{
	d->map = NULL;
	d->max.x = 1;
	d->max.y = 0;
	d->max.z = 0;
	d->map_size = 0;
	d->zoom = 5;
	d->move_h = 0;
	d->move_v = 0;
	d->proj = 1;
}

void		ft_init_mlx(t_fdf *d, char *file)
{
	ft_init_data(d);
	ft_read_file(d, file);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIN_X, WIN_Y, "FDF");
	d->img = mlx_new_image(d->mlx, WIN_X, WIN_Y);
	ft_draw(d);
	mlx_key_hook(d->win, get_key, d);
	mlx_expose_hook(d->win, expose_hook, d);
	mlx_loop(d->mlx);
}
