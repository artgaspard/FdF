/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 11:57:00 by agaspard          #+#    #+#             */
/*   Updated: 2017/03/18 14:06:40 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		resize(t_siz *s, t_env *e)
{
	if (s->xmin > e->xi)
		s->xmin = e->xi;
	if (s->xmin > e->xf)
		s->xmin = e->xf;
	if (s->xmax < e->xi)
		s->xmax = e->xi;
	if (s->xmax < e->xf)
		s->xmax = e->xf;
	if (s->ymin > e->yi)
		s->ymin = e->yi;
	if (s->ymin > e->yf)
		s->ymin = e->yf;
	if (s->ymax < e->yi)
		s->ymax = e->yi;
	if (s->ymax < e->yf)
		s->ymax = e->yf;
}

void		init(t_siz *s, t_env *e)
{
	e->x = 0;
	e->y = 0;
	e->x_mid = 0;
	e->y_mid = 0;
	iso(e, 0);
	s->xmin = e->xi;
	s->xmax = e->xf;
	s->ymin = e->yi;
	s->ymax = e->yf;
	e->y = 0;
}

t_siz		*win_size(t_env *e)
{
	t_siz	*s;

	if ((s = (t_siz*)malloc(sizeof(t_siz))) == 0)
		return (0);
	init(s, e);
	while (++(e->y) < e->ymax)
	{
		e->x = 0;
		while (++(e->x) < e->xmax)
		{
			if (e->x + 1 < e->xmax)
			{
				iso(e, 0);
				resize(s, e);
			}
			if (e->y + 1 < e->ymax)
			{
				iso(e, 1);
				resize(s, e);
			}
		}
	}
	return (s);
}
