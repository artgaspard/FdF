/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:44:22 by agaspard          #+#    #+#             */
/*   Updated: 2017/02/21 13:41:35 by agaspard         ###   ########.fr       */
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

# include "libft/includes/libft.h"
# include "gnl/get_next_line.h"

# define KEY_ESC 53

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	int			xi;
	int			yi;
	int			xf;
	int			yf;
}				t_env;

int		get_next_line(int const fd, char **line);
void	parse_fd(char **av, t_env *e);

#endif
