/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:39:49 by agaspard          #+#    #+#             */
/*   Updated: 2017/03/17 17:38:33 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	height_color(t_env *e)
{
	if ((e->zi + e->zf) / 2 < 0)
	{
		e->r = 0;
		e->g = 133;
		e->b = 202;
	}
	if ((e->zi + e->zf) / 2 == 0)
	{
		e->r = 0;
		e->g = 204;
		e->b = 0;
	}
	if ((e->zi + e->zf) / 2 > e->zmax * 0.8)
	{
		e->r = 255;
		e->g = 255;
		e->b = 255;
	}
	if ((e->zi + e->zf) / 2 > 0 && (e->zi + e->zf) / 2 <= e->zmax * 0.8)
	{
		e->r = 222;
		e->g = 124;
		e->b = 0;
	}
}

int		gere_key(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_LEFT)
		e->mv_lr -= 10;
	if (keycode == KEY_RIGHT)
		e->mv_lr += 10;
	if (keycode == KEY_UP)
		e->mv_ud += 10;
	if (keycode == KEY_DOWN)
		e->mv_ud -= 10;
	if (keycode == KEY_PLUS)
		e->zoom += 0.1;
	if (keycode == KEY_MINUS && e->zoom > 0)
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
