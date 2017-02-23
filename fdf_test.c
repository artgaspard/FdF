/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:06:43 by agaspard          #+#    #+#             */
/*   Updated: 2017/02/22 16:16:22 by agaspard         ###   ########.fr       */
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
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &(e->endian));
}	

void	put_pixel(t_env *e, int x, int y)
{
		e->data[(y * 1000) + x] = 0xFFFFFF;
}

void	print_line(t_env *e)
{
	int x;
	int y;
	int dx;
	int dy;
	int	xinc;
	int	yinc;
	int cumul;
	int i;

	e->xi = 200;
	e->yi = 200;
	e->xf = 800;
	e->yf = 800;
	x = e->xi;
	y = e->yi;
	dx = e->xf - x;
	dy = e->yi - y;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	if (dx > dy)
	{
		cumul = dx / 2;
		i = 1;
		while (i <= dx)
		{
			x += xinc;
			cumul += dy;
			i++;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			put_pixel(e, x, y);
		}
	}
	else
	{
		cumul = dy / 2;
		i = 1;
		while (i <= dy)
		{
			y += yinc;
			cumul += dx;
			i++;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			put_pixel(e, x, y);
		}
	}
}


int		gere_key(int keycode, void *data)
{
	(void)data;
	if (keycode == KEY_ESC)
		exit(0);
	return (1);
}

int	main()
{
	t_env	*e;

//	if (ac == 1)
//		return (0);
	if ((e = (t_env*)malloc(sizeof(t_env))) == 0)
		return (0);
	init_mlx(e);
//	parse_fd(av[1], e);
	create_img(e);
	print_line(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_key_hook(e->win, gere_key, e);
	mlx_destroy_image(e->mlx, e->img);
	mlx_loop(e->mlx);
	return (0);
}
