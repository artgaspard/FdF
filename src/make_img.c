/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:06:43 by agaspard          #+#    #+#             */
/*   Updated: 2017/03/09 17:55:46 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1000, 1000, "fdf");
	e->r = 255;
	e->g = 255;
	e->b = 255;
	e->zoom = 1;
}

void	create_img(t_env *e)
{
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->szl), &(e->endian));
}	

void	put_pixel(t_env *e, int x, int y)
{
	if (x >= 0 && y >= 0 && x < 1000 && y < 1000)
	{
		e->data[(y * e->szl) + (x * 4)] = e->r;
		e->data[(y * e->szl) + (x * 4) + 1] = e->g;
		e->data[(y * e->szl) + (x * 4) + 2] = e->b;
	}
}

int		fdf(int ac, char **av)
{
	t_env	*e;

	if (ac == 2 || ac == 4)
	{
		if ((e = (t_env*)malloc(sizeof(t_env))) == 0)
			return (0);
		init_mlx(e);
		create_img(e);
		if (get_max(av[1], e) == -1)
		{
			ft_putstr("Found wrong line length. Exiting.\n");
			return (0);
		}
		set_map(av[1], e);
		if (ac == 4)
		{
			e->case_size = ft_atoi(av[2]);
			e->z_size = ft_atoi(av[3]);
		}
		else
		{
			e->case_size = 30;
			e->z_size = 2;
		}
		get_coor(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_hook(e->win, 2, 3, gere_key, e);
		mlx_loop_hook(e->mlx, &loop_event, e);
		mlx_destroy_image(e->mlx, e->img);
		mlx_loop(e->mlx);
	}
	else
	{
		ft_putstr("Usage : ./");
		ft_putstr(av[1]);
		ft_putstr(" <filename> [ case_size z_size ]\n");
	}
	return (0);
}
