/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:21:15 by agaspard          #+#    #+#             */
/*   Updated: 2017/02/25 16:30:19 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_line(char *line, int x)
{
	int		i;
	int		nbr_dot;

	nbr_dot = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] && line[i] != '\n' && line[i] != ' ' && ft_isdigit(line[i]) == 0)
			return (-1);
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] && ft_isdigit(line[i]) == 1)
			nbr_dot++;
		while (line[i] && ft_isdigit(line[i]) == 1)
			i++;
	}
	if (nbr_dot >= x)
		return (nbr_dot);
	return (x);
}

int			get_max(char *av, t_env *e)
{
	char	*line;
	int		fd;
	int		x;
	int		y;

	x = 0;
	y = 0;
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		x = check_line(line, x);
		if (x == -1)
			return (-1);
		if (line)
			free(line);
		y++;
	}
	close(fd);
	e->xmax = x;
	e->ymax = y;
	printf("%d\n", e->xmax);
	printf("%d\n", e->ymax);
	return (0);
}

int			check_error(int ac, char **av, t_env *e)
{
	if (ac == 2)
	{
		if (get_max(av[1], e) == -1)
			return (-1);
		return (0);
	}
	else
		ft_putstr_fd("usage: fdf [file]", 2);
	return (-1);
}
