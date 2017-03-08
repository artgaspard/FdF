/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 10:45:51 by agaspard          #+#    #+#             */
/*   Updated: 2017/03/08 17:31:04 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(t_env *e, int x, int y)
{
	if (x >= 0 && y >= 0 && x < 1000 && y < 1000)
	{
		e->data[(y * e->szl) + (x * 4)] = e->r;
		e->data[(y * e->szl) + (x * 4) + 1] = e->g;
		e->data[(y * e->szl) + (x * 4) + 2] = e->b;
	}
}

void		bresenham(t_env *e, t_bres *b, float x, float y, int count)
{
	float	cumul;
	int		i;

	i = 1;
	if (count == 0)
	{
		cumul = b->dx / 2;
		while (i++ <= b->dx)
		{
			x += b->xinc;
			cumul += b->dy;
			if (cumul >= b->dx)
			{
				cumul -= b->dx;
				y += b->yinc;
			}
			put_pixel(e, x, y);
		}
	}
	else
	{
		cumul = b->dy / 2;
		while (i++ <= b->dy)
		{
			y += b->yinc;
			cumul += b->dx;
			if (cumul >= b->dy)
			{
				cumul -= b->dy;
				x += b->xinc;
			}
			put_pixel(e, x, y);
		}
	}
}

void		print_line(t_env *e)
{
	float	x;
	float	y;
	t_bres	*b;

	if ((b = (t_bres*)malloc(sizeof(t_bres))) == 0)
		return ;
	x = e->xi;
	y = e->yi;
	b->dx = e->xf - x;
	b->dy = e->yf - y;
	b->xinc = (b->dx > 0) ? 1 : -1;
	b->yinc = (b->dy > 0) ? 1 : -1;
	b->dx = (e->xf - e->xi >= 0) ? b->dx : -(b->dx);
	b->dy = (e->yf - e->yi >= 0) ? b->dy : -(b->dy);
	if (b->dx > b->dy)
		bresenham(e, b, x, y, 0);
	else
		bresenham(e, b, x, y, 1);
}

void		iso_2D(t_env *e, int x, int y, int count)
{
	double	cte1;
	double	cte2;

	cte1 = 1;
	cte2 = 1;
	e->z = e->map[y][x];
	e->xi = (cte1 * x - cte2 * y) * 30 + 350;
	e->yi = (-(e->map[y][x] / 4) + cte1 / 2 * x + cte2 / 2 * y) * 30 + 350;
	if (count == 0)
		x++;
	else
		y++;
	e->xf = (cte1 * x - cte2 * y) * 30 + 350;
	e->yf = (-(e->map[y][x] / 4) + cte1 / 2 * x + cte2 / 2 * y) * 30 + 350;
}

void		get_coor_3D(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < e->ymax)
	{
		x = 0;
		while (x < e->xmax)
		{
			if (x + 1 < e->xmax)
			{
				iso_2D(e, x, y, 0);
				height_color(e);
				print_line(e);
			}
			if (y + 1 < e->ymax)
			{
				iso_2D(e, x, y, 1);
				height_color(e);
				print_line(e);
			}
			x++;
		}
		y++;
	}
}
