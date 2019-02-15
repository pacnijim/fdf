#include "../includes/fdf.h"

static void		ft_get_map(char **map, t_fdf *d)
{
	int		i;
	int		x;
	int		y;
	char	**tmp;

	i = 0;
	y = 0;
	d->map_size = d->max.x * d->max.y;
	d->map = (t_point*)malloc(sizeof(t_point) * (d->map_size + 1));
	while (*map)
	{
		tmp = ft_strsplit(*map, ' ');
		x = 0;
		while (*tmp)
		{
			d->map[i].x = x++;
			d->map[i].y = y;
			d->map[i++].z = ft_atoi(*tmp);
			tmp++;
		}
		y++;
		map++;
	}
}

static void		ft_init_map(char *map, t_fdf *d, int j)
{
	char	**split;
	int		i;

	split = ft_strsplit(map, '\n');
	while (split[++j])
	{
		i = -1;
		split[j] = ft_epur_str(split[j]);
		while (split[j][++i])
		{
			if (split[j][i] == ' ' && d->max.y == 0)
				d->max.x++;
			if (split[j][i] == ' ' && d->max.y > 0)
				d->max.z++;
		}
		if (d->max.x != d->max.z && d->max.y > 0)
		{
			ft_putstr("Found wrong line lengh. Existing\n");
			exit(-1);
		}
		d->max.y++;
		d->max.z = 1;
	}
	ft_get_map(split, d);
}

static void		ft_check_map(char *map)
{
	while (*map)
	{
		if ((*map < '0' || *map > '9') && *map != '-' && *map != ' '
			&& *map != '\n')
		{
			ft_putstr("Found wrong line lengh. Existing\n");
			exit(-1);
		}
		map++;
	}
}

void			ft_read_file(t_fdf *d, char *name)
{
	int		fd;
	int		rd;
	char	*buf;
	char	*map;

	fd = open(name, O_RDONLY);
	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	map = ft_strnew(0);
	if (fd == -1)
	{
		ft_putstr("No file ");
		ft_putstr(name);
		ft_putchar('\n');
		exit(-1);
	}
	while ((rd = read(fd, buf, BUFF_SIZE) > 0))
	{
		map = ft_strjoin(map, buf);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	free(buf);
	ft_check_map(map);
	ft_init_map(map, d, -1);
	close(fd);
}
