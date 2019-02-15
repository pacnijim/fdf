#include "../includes/fdf.h"

int				main(int ac, char **av)
{
	t_fdf		d;														/*t_fdf déclarer*/

	if (ac == 2)
		ft_init_mlx(&d, av[1]);											/*ok 1 arg -> on envoie la struct d(t_fdf) et le nom du fichier av[1]*/
	else
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");	/*error arg*/
	return (0);
}
