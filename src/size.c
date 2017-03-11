/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 11:57:00 by agaspard          #+#    #+#             */
/*   Updated: 2017/03/11 14:52:06 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_siz		win_size(t_env *e)
{
	t_siz	s;

	e->x = 0;
	e->y = 0;
	e->x_mid = 0;
	e->y_mid = 0;
	iso(e, 0);
	s.xmin = e->xi;
	s.xmax = e->xf;
	s.ymin = e->yi;
	s.ymax = e->yf;
	e->y = 0;
	while (e->y < e->ymax)
	{
		e->x = 0;
		while (e->x < e->xmax)
		{
			if (e->x + 1 < e->xmax)
			{
				iso(e, 0);
				if (s.xmin > e->xi)
					s.xmin = e->xi;
				if (s.xmin > e->xf)
					s.xmin = e->xf;
				if (s.xmax < e->xi)
					s.xmax = e->xi;
				if (s.xmax < e->xf)
					s.xmax = e->xf;
				if (s.ymin > e->yi)
					s.ymin = e->yi;
				if (s.ymin > e->yf)
					s.ymin = e->yf;
				if (s.ymax < e->yi)
					s.ymax = e->yi;
				if (s.ymax < e->yf)
					s.ymax = e->yf;
			}
			if (e->y + 1 < e->ymax)
			{
				iso(e, 1);
				if (s.xmin > e->xi)
					s.xmin = e->xi;
				if (s.xmin > e->xf)
					s.xmin = e->xf;
				if (s.xmax < e->xi)
					s.xmax = e->xi;
				if (s.xmax < e->xf)
					s.xmax = e->xf;
				if (s.ymin > e->yi)
					s.ymin = e->yi;
				if (s.ymin > e->yf)
					s.ymin = e->yf;
				if (s.ymax < e->yi)
					s.ymax = e->yi;
				if (s.ymax < e->yf)
					s.ymax = e->yf;
			}
			(e->x)++;
		}
		(e->y)++;
	}
	return (s);
}
