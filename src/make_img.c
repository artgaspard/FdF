/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:06:43 by agaspard          #+#    #+#             */
/*   Updated: 2017/02/28 16:55:49 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1000, 1000, "test");
}

void	create_img(t_env *e)
{
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->szl), &(e->endian));
}	

int		fdf(int ac, char **av)
{
	t_env	*e;

	if (ac == 2)
	{
		if ((e = (t_env*)malloc(sizeof(t_env))) == 0)
			return (0);
		init_mlx(e);
		if (get_max(av[1], e) == -1)
		{
			ft_putstr("Found wrong line length. Exiting.\n");
			return (0);
		}
		set_map(av[1], e);
		get_coor_3D(e);
		create_img(e);
		print_line(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_key_hook(e->win, gere_key, e);
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
