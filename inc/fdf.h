/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:44:22 by agaspard          #+#    #+#             */
/*   Updated: 2017/03/08 17:31:12 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# define KEY_ESC 53

typedef struct	s_bres
{
	float		dx;
	float		dy;
	float		xinc;
	float		yinc;
}				t_bres;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			szl;
	int			endian;
	int			xmax;
	int			ymax;
	int			xi;
	int			yi;
	int			xf;
	int			yf;
	int			z;
	int			r;
	int			g;
	int			b;
	int			**map;
}				t_env;

void	height_color(t_env *e);
int		gere_key(int keycode, t_env *e);
int		loop_event(t_env *e);
void	create_img(t_env *e);
void	put_pixel(t_env *e, int x, int y);
void	print_line(t_env *e);
int		fdf(int ac, char **av);
int		get_max(char *av, t_env *e);
void	*set_map(char *av, t_env *e);
void	get_coor_3D(t_env *e);

#endif
