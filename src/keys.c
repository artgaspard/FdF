/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:39:49 by agaspard          #+#    #+#             */
/*   Updated: 2017/03/11 15:13:16 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	height_color(t_env *e)
{
	if ((e->zi + e->zf) < 0)
	{
		e->r = 0;
		e->g = 128;
		e->b = 255;
	}
	if ((e->zi + e->zf) >= 0 && (e->zi + e->zf) < 10)
	{
		e->r = 0;
		e->g = 204;
		e->b = 0;
	}
	if ((e->zi + e->zf) >= 10 && (e->zi + e->zf) < 20)
	{
		e->r = 0;
		e->g = 102;
		e->b = 204;
	}
	if ((e->zi + e->zf) >= 20)
	{
		e->r = 255;
		e->g = 255;
		e->b = 255;
	}
}

int		gere_key(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_R && e->r + 10 < 255)
		e->r += 10;
	if (keycode == KEY_T && e->r - 10 > 0)
		e->r -= 10;
	if (keycode == KEY_G && e->g + 10 < 255)
		e->g += 10;
	if (keycode == KEY_H && e->g - 10 > 0)
		e->g -= 10;
	if (keycode == KEY_B && e->b + 10 < 255)
		e->b += 10;
	if (keycode == KEY_N && e->b - 10 > 0)
		e->b -= 10;
	if (keycode == 13)
	{
		e->r = 255;
		e->g = 255;
		e->b = 255;
	}
	if (keycode == KEY_PLUS)
		e->zoom += 0.1;
	if (keycode == KEY_MINUS && e->zoom -0.1 > 0)
		e->zoom -= 0.1;
	return (0);
}

int		loop_event(t_env *e)
{
	create_img(e);
	get_coor(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}

