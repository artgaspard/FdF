/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:39:49 by agaspard          #+#    #+#             */
/*   Updated: 2017/03/18 15:19:19 by agaspard         ###   ########.fr       */
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

int		gere_key2(int keycode, t_env *e)
{
	if (keycode == KEY_CTE_2_PLUS && e->cte2 < 1)
		e->cte2 += 0.1;
	if (keycode == KEY_CTE_2_MINUS && e->cte2 > 0.5)
		e->cte2 -= 0.1;
	if (keycode == KEY_Z_PLUS)
		e->z_size += 0.1;
	if (keycode == KEY_Z_MINUS)
		e->z_size -= 0.1;
	return (0);
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
	if (keycode == KEY_CTE_1_PLUS && e->cte1 < 1)
		e->cte1 += 0.1;
	if (keycode == KEY_CTE_1_MINUS && e->cte1 > 0.5)
		e->cte1 -= 0.1;
	gere_key2(keycode, e);
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
