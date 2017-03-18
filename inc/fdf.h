/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:44:22 by agaspard          #+#    #+#             */
/*   Updated: 2017/03/18 16:17:46 by agaspard         ###   ########.fr       */
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
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 125
# define KEY_DOWN 126
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_CTE_1_PLUS 86
# define KEY_CTE_1_MINUS 83
# define KEY_CTE_2_PLUS 87
# define KEY_CTE_2_MINUS 84
# define KEY_Z_PLUS 88
# define KEY_Z_MINUS 85

typedef	struct	s_siz
{
	int			xmin;
	int			xmax;
	int			ymin;
	int			ymax;
}				t_siz;

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
	int			zmax;
	int			x;
	int			y;
	int			xi;
	int			yi;
	int			xf;
	int			yf;
	int			zi;
	int			zf;
	int			r;
	int			g;
	int			b;
	int			case_size;
	int			width;
	int			height;
	int			x_mid;
	int			y_mid;
	int			mv_lr;
	int			mv_ud;
	int			**map;
	double		z_size;
	double		cte1;
	double		cte2;
	float		zoom;
	float		dx;
	float		dy;
	float		xinc;
	float		yinc;
	float		cumul;
	t_siz		*w_size;
}				t_env;

void			init_mlx(t_env *e);
void			create_img(t_env *e);
void			put_pixel(t_env *e, int x, int y);
int				error_fd(char **av, t_env *e, int error);
int				fdf(int ac, char **av);
void			height_color(t_env *e);
int				gere_key(int keycode, t_env *e);
int				gere_key2(int keycode, t_env *e);
int				loop_event(t_env *e);
void			vertical_line(t_env *e, int x, int y);
void			horizontal_line(t_env *e, int x, int y);
void			print_line(t_env *e);
void			iso(t_env *e, int count);
void			get_coor(t_env *e);
int				check_len(char *line, int x, int first_line);
int				check_line(char *line, int x);
int				get_max(char *av, t_env *e);
void			get_map(int *x, int y, char **tab, t_env *e);
void			set_map(char *av, t_env *e);
void			resize(t_siz *s, t_env *e);
void			init(t_siz *s, t_env *e);
t_siz			*win_size(t_env *e);

#endif
