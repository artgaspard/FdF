/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <agaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:21:15 by agaspard          #+#    #+#             */
/*   Updated: 2017/03/10 14:54:32 by agaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_len(char *line, int x, int first_line)
{
	int		len;

	len = ft_arraylen(ft_strsplit(line, ' '));
	if (first_line != 0)
	{
		if (len != x)
			return (-1);
		return (len);
	}
	return (len);
}

int			check_line(char *line, int x)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] && line[i] != '\n' && line[i] != ' ' \
				&& ft_isdigit(line[i]) == 0)
			return (-1);
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] && ft_isdigit(line[i]) == 1)
			len++;
		while (line[i] && ft_isdigit(line[i]) == 1)
			i++;
	}
	if (len >= x)
		return (len);
	return (x);
}

int			get_max(char *av, t_env *e)
{
	char	*line;
	int		fd;
	int		x;
	int		y;
	int		first_line;

	fd = open(av, O_RDONLY);
	x = 0;
	y = 0;
	first_line = 0;
	while (get_next_line(fd, &line) == 1)
	{
		x = check_line(line, x);
		if (x == -1 || (x = check_len(line, x, first_line)) == -1)
			return (-1);
		if (line)
			free(line);
		y++;
		first_line++;
	}
	close(fd);
	e->xmax = x;
	e->ymax = y;
	return (0);
}

void		get_map(int *x, int y, char **tab, t_env *e)
{
	int		i;

	i = 0;
	while (tab[i] && *x < e->xmax)
	{
		e->map[y][*x] = ft_atoi(tab[i]);
		(*x)++;
		i++;
	}
}

void		set_map(char *av, t_env *e)
{
	char	**tab;
	char	*line;
	int		fd;
	int		x;
	int		y;

	tab = NULL;
	fd = open(av, O_RDONLY);
	x = 0;
	y = 0;
	if ((e->map = (int**)malloc(sizeof(int*) * e->ymax)) == 0)
		return ;
	while (get_next_line(fd, &line) == 1 && y < e->ymax)
	{
		if ((e->map[y] = (int*)malloc(sizeof(int) * e->xmax)) == 0)
			return ;
		tab = ft_strsplit(line, ' ');
		if (tab)
			get_map(&x, y, tab, e);
		x = 0;
		if (tab)
			free(tab);
		y++;
	}
	close(fd);
}
