/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:06:43 by agaspard          #+#    #+#             */
/*   Updated: 2017/02/21 10:30:37 by agaspard         ###   ########.fr       */
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

void	put_pixel(t_env *e)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while ((x > 0 && y > 0) && (x < 1000 && y < 1000))
	{
		e->data[(y * 1000 * 4) + (x * 4)] = 255;
		e->data[(y * 1000 * 4) + (x * 4) + 1] = 255;
		e->data[(y * 1000 * 4) + (x * 4) + 2] = 255;
		e->data[(y * 1000 * 4) + (x * 4) + 3] = 255;
	}
}

int		gere_key(int keycode, t_env *e)
{
	e = 0;
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
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
	put_pixel(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_key_hook(e->win, gere_key, e);
	mlx_destroy_image(e->mlx, e->img);
	mlx_loop(e->mlx);
	return (0);
}
