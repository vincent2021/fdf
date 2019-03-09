/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:01:05 by vimucchi          #+#    #+#             */
/*   Updated: 2019/03/09 15:40:10 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line		*ft_get_map(int fd)
{
	int		i;
	char	*line;
	t_line	*lst;
	t_line	*begin;

	if (!(lst = (t_line *)malloc(sizeof(t_line))))
		return (0);
	begin = lst;
	lst->str = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (!(lst->str = ft_strsplit(line, ' ')))
			return (0);
		i = 0;
		while (lst->str[i])
			i++;
		lst->x_str = i;
		if (!(lst->next = (t_line *)malloc(sizeof(t_line))))
			return (0);
		lst = lst->next;
		lst->str = NULL;
		free(line);
	}
	lst->next = NULL;
	return (begin);
}

void		ft_check_map(t_line *line, t_parse *map)
{
	t_line	*tmp;
	int		nb_line;

	tmp = line;
	nb_line = 0;
	while (tmp->next)
	{
		if (line->x_str != tmp->x_str)
			ft_error_map(0);
		tmp = tmp->next;
		nb_line++;
	}
	if (nb_line == 0)
		ft_error_map(0);
	if (line->x_str == 1 && nb_line == 1)
		ft_error_map(0);
	map->x_tab = line->x_str;
	map->y_tab = nb_line;
}

int			ft_check_alt(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error_map(0);
		i++;
	}
	return (0);
}

int			ft_free_lst(t_line *line)
{
	int		i;

	if (!line)
		ft_error_map(1);
	if (line->next != NULL)
		ft_free_lst(line->next);
	i = 0;
	while (line->str && line->str[i])
	{
		free(line->str[i]);
		i++;
	}
	if (line->str)
		free(line->str);
	if (line)
		free(line);
	return (0);
}

t_parse		ft_get_tab(t_line *line)
{
	t_parse	map;
	t_line	*begin;
	int		i;
	int		j;

	begin = line;
	ft_check_map(line, &map);
	if (!(map.tab = (int **)malloc(sizeof(int **) * map.y_tab)))
		ft_error_map(3);
	j = 0;
	while (line->next)
	{
		if (!(map.tab[j] = (int *)malloc(sizeof(int *) * line->x_str)))
			ft_error_map(3);
		i = 0;
		while (i < line->x_str && ft_check_alt(line->str[i]) == 0)
		{
			map.tab[j][i] = atoi(line->str[i]);
			i++;
		}
		j++;
		line = line->next;
	}
	ft_free_lst(begin);
	return (map);
}
