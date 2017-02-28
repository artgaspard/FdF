/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 10:45:51 by agaspard          #+#    #+#             */
/*   Updated: 2017/02/28 17:00:28 by agaspard         ###   ########.fr       */
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

	x = e->xi;
	y = e->yi;
	dx = e->xf - x;
	dy = e->yf - y;
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
void	iso_2D(int x, int y, int z, t_env *e)
{
	int xiso;
	int	yiso;
	double	cte1;
	double	cte2;

	cte1 = 1;
	cte2 = 1;
	xiso = (cte1 * x) - (cte2 * y);
	yiso = z + ((cte1 / 2) * x) + ((cte2 / 2) * y);
	e->xf = xiso;
	e->yf = yiso;
}
*/
void	get_coor_3D(t_env *e)
{
	int	x;
	int y;
	int	y2;

	x = 0;
	y = 0;
	y2 = 1;
	while (y < e->ymax)
	{
		while (x < e->xmax)
		{
			e->xi = e->map[y][x];
			printf("xi = %d\n", e->map[y][x]);
			e->yi = *(e->map[y]);
			printf("yi = %d\n", *(e->map[y]));
			e->xf = e->map[y2][x];
			printf("xf = %d\n", e->map[y2][x]);
			e->yf = *(e->map[y2]);
			printf("yf = %d\n", *(e->map[y2]));
			print_line(e);
			x++;
			y2++;
		}
		x = 0;
		y++;
		y2 = y;
	}
}
