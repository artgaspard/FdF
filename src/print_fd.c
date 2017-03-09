/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 10:45:51 by agaspard          #+#    #+#             */
/*   Updated: 2017/03/09 19:17:19 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		vertical_line(t_env *e, int x, int y)
{
	int		i;

	i = 1;
	e->cumul = e->dx / 2;
	while (i++ <= e->dx)
	{
		x += e->xinc;
		e->cumul += e->dy;
		if (e->cumul >= e->dx)
		{
			e->cumul -= e->dx;
			y += e->yinc;
		}
		put_pixel(e, x, y);
	}
}

void		horizontal_line(t_env *e, int x, int y)
{
	int		i;

	i = 1;
	e->cumul = e->dy / 2;
	while (i++ <= e->dy)
	{
		y += e->yinc;
		e->cumul += e->dx;
		if (e->cumul >= e->dy)
		{
			e->cumul -= e->dy;
			x += e->xinc;
		}
		put_pixel(e, x, y);
	}
}

void		print_line(t_env *e)
{
	float	x;
	float	y;

	x = e->xi;
	y = e->yi;
	e->dx = e->xf - x;
	e->dy = e->yf - y;
	e->xinc = (e->dx > 0) ? 1 : -1;
	e->yinc = (e->dy > 0) ? 1 : -1;
	e->dx = (e->xf - e->xi >= 0) ? e->dx : -(e->dx);
	e->dy = (e->yf - e->yi >= 0) ? e->dy : -(e->dy);
	if (e->dx > e->dy)
		vertical_line(e, x, y);
	else
		horizontal_line(e, x, y);
}

void		iso(t_env *e, int x, int y, int count)
{
	double	cte1;
	double	cte2;

	cte1 = 1;
	cte2 = 1;
	e->zi = e->map[y][x];
	e->xi = ((cte1 * x - cte2 * y) * e->case_size + 300) * e->zoom;;
	e->yi = ((-(e->zi * e->z_size / 10) + cte1 / 2 * x + cte2 / 2 * y) * e->case_size + 300) * e->zoom;
	if (count == 0)
		x++;
	else
		y++;
	e->zf = e->map[y][x];
	e->xf = ((cte1 * x - cte2 * y) * e->case_size + 300) * e->zoom;
	e->yf = ((-(e->zf * e->z_size / 10) + cte1 / 2 * x + cte2 / 2 * y) * e->case_size + 300) * e->zoom;
}

void		get_coor(t_env *e)
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
				iso(e, x, y, 0);
				height_color(e);
				print_line(e);
			}
			if (y + 1 < e->ymax)
			{
				iso(e, x, y, 1);
				height_color(e);
				print_line(e);
			}
			x++;
		}
		y++;
	}
}
