/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:06:43 by agaspard          #+#    #+#             */
/*   Updated: 2017/03/27 15:10:58 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_env *e)
{
	e->zoom = 1;
	e->cte1 = 1;
	e->cte2 = 1;
	e->w_size = win_size(e);
	e->x_mid = abs(e->w_size->xmin) + 30;
	e->y_mid = abs(e->w_size->ymin) + 20;
	e->width = abs(e->w_size->xmin) + abs(e->w_size->xmax) + 60;
	e->height = abs(e->w_size->ymin) + abs(e->w_size->ymax) + 40;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "fdf");
	create_img(e);
}

void	create_img(t_env *e)
{
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->szl), &(e->endian));
}

void	put_pixel(t_env *e, int x, int y)
{
	if (x >= 0 && y >= 0 && x < e->width && y < e->height)
	{
		e->data[(y * e->szl) + (x * 4)] = e->b;
		e->data[(y * e->szl) + (x * 4) + 1] = e->g;
		e->data[(y * e->szl) + (x * 4) + 2] = e->r;
	}
}

int		error_fd(char **av, t_env *e, int error)
{
	if (error == 1)
	{
		ft_putstr("Found wrong line length. Exiting.\n");
		return (1);
	}
	if (error == 2)
	{
		ft_putstr("Usage : ./");
		ft_putstr(av[1]);
		ft_putstr(" <filename> [ case_size z_size ]\n");
		return (1);
	}
	if (error == 3)
	{
		e->case_size = 30;
		e->z_size = 2;
	}
	if (error == 4)
	{
		e->case_size = ft_atoi(av[2]);
		e->z_size = ft_atoi(av[3]);
	}
	return (0);
}

int		fdf(int ac, char **av)
{
	t_env	*e;

	if ((e = (t_env*)malloc(sizeof(t_env))) == 0)
		return (0);
	if (ac == 2 || ac == 4)
	{
		if (get_max(av[1], e) == 1)
			return (0);
		if (get_max(av[1], e) == -1)
			return (error_fd(av, e, 1));
		set_map(av[1], e);
		if (ac == 4)
			error_fd(av, e, 4);
		else
			error_fd(av, e, 3);
		init_mlx(e);
		get_coor(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_hook(e->win, 2, 3, gere_key, e);
		mlx_loop_hook(e->mlx, &loop_event, e);
		mlx_loop(e->mlx);
	}
	else
		return (error_fd(av, e, 2));
	return (0);
}
