/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 10:45:51 by agaspard          #+#    #+#             */
/*   Updated: 2017/03/02 18:37:39 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_env *e, int x, int y)
{
	if ((x >= 0 && y >= 0) && (x <= 1000 && y <= 1000))
	{
		e->data[(y * e->szl) + (x * 4)] = 255;
		e->data[(y * e->szl) + (x * 4) + 1] = 255;
		e->data[(y * e->szl) + (x * 4) + 2] = 255;
		e->data[(y * e->szl) + (x * 4) + 3] = 100;
	}
}

void    print_line(t_env *e)
{
	int x;
	int y;
	int dx;
	int dy;
	int xinc;
	int yinc;
	int cumul;
	int i;

	x = e->xi * 50;
	y = e->yi * 50;
	dx = (e->xf * 50) - x;
	dy = (e->yf * 50) - y;
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
/*
void	iso_2D_1(int x, int y, int z, t_env *e)
{
	int xiso;
	int	yiso;
	double	cte1;
	double	cte2;

	cte1 = 1;
	cte2 = 1;
	x = e->xi;
	y = e->yi;
	z = e->z;
	xiso = (cte1 * x) - (cte2 * y);
	yiso = z + ((cte1 / 2) * x) + ((cte2 / 2) * y);
	e->xi = xiso;
	e->yi = yiso;
}
*/
void	get_coor_3D(t_env *e)
{
	int	x;
	int y;
	int z;

	y = 0;
	z = 0;
	while (y <= e->ymax)
	{
		x = 0;
		while (x <= e->xmax)
		{
			e->xi = x;
			e->yi = y;
		//	e->z = e->map[x][y];
			if (y + 1 <= e->ymax && x != 0)
			{
				e->yf = y + 1;
				print_line(e);
			}
			if (x + 1 <= e->xmax)
				e->xf = x + 1;
			else
				e->xf = x;
			e->yf = y;
			print_line(e);
			x++;
		}
		y++;
	}
}
