/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:39:49 by agaspard          #+#    #+#             */
/*   Updated: 2017/03/08 17:31:07 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	height_color(t_env *e)
{
	e->z = -(e->z);
	if (e->z < 0)
	{
		e->r = 0;
		e->g = 102;
		e->b = 204;
	}
	if ((e->z >= 0 && e->z < 10) && ((e->z)++) > e->z)
	{
		e->r = 0;
		e->g = 204;
		e->b = 0;
	}
	if ((e->z >= 10 && e->z < 20) && ((e->z)++) > e->z)
	{
		e->r = 153;
		e->g = 76;
		e->b = 0;
	}
	if (e->z > 20 && (e->z)++ > e->z)
	{
		e->r = 255;
		e->g = 255;
		e->b = 255;
	}
	e->z = -(e->z);
}

int		gere_key(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == 15 && e->r + 10 < 255)
		e->r += 10;
	if (keycode == 17 && e->r - 10 > 0)
		e->r -= 10;
	if (keycode == 5 && e->g + 10 < 255)
		e->g += 10;
	if (keycode == 4 && e->g - 10 > 0)
		e->g -= 10;
	if (keycode == 11 && e->b + 10 < 255)
		e->b += 10;
	if (keycode == 45 && e->b - 10 > 0)
		e->b -= 10;
	if (keycode == 13)
	{
		e->r = 255;
		e->g = 255;
		e->b = 255;
	}
	return (0);
}

int		loop_event(t_env *e)
{
	create_img(e);
	get_coor_3D(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}

