/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:24:52 by vimucchi          #+#    #+#             */
/*   Updated: 2018/12/03 16:49:31 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_getline(t_gnl *mem, char **line, int c_rd)
{
	size_t			i;
	size_t			l;
	char			*tmp;

	i = 0;
	l = ft_strlen(mem->str);
	while (mem->str[i] && mem->str[i] != '\n')
		i++;
	if (c_rd < BUFF_SIZE && (l == i + 1 || (l = i && mem->str[i] != '\n')))
	{
		*line = ft_strnew(i);
		*line = ft_strncpy(*line, mem->str, i);
		ft_bzero(mem->str, l);
		return (1);
	}
	else if (mem->str[i] == '\n')
	{
		*line = ft_strnew(i);
		*line = ft_strncpy(*line, mem->str, i);
		tmp = ft_strdup(mem->str + i + 1);
		ft_strdel(&mem->str);
		mem->str = tmp;
		return (1);
	}
	return (0);
}

void				ft_cpybuf(t_gnl *mem, char *buf)
{
	char			*tmp;

	if (!mem->str)
		mem->str = ft_strdup(buf);
	else
	{
		tmp = mem->str;
		mem->str = ft_strjoin(mem->str, buf);
		ft_strdel(&tmp);
	}
}

int					ft_read(int fd, char **line, t_gnl *mem)
{
	char			*buf;
	size_t			c_rd;

	if (!(buf = malloc((BUFF_SIZE + 1) * sizeof(char))))
		return (-1);
	while ((c_rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[c_rd] = '\0';
		ft_cpybuf(mem, buf);
		if (ft_getline(mem, line, c_rd))
		{
			ft_strdel(&buf);
			return (1);
		}
	}
	if (ft_getline(mem, line, 0) == 1)
	{
		ft_strdel(&buf);
		return (1);
	}
	free(buf);
	return (0);
}

t_gnl				*ft_lst_new(int fd, t_gnl *mem)
{
	t_gnl			*new;

	if (!(new = malloc(sizeof(t_gnl))))
		return (0);
	new->fd = fd;
	new->str = NULL;
	new->next = mem;
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*mem = NULL;
	t_gnl			*tmp;

	if (line == NULL || read(fd, NULL, 0) == -1 || fd < 0)
		return (-1);
	if (!mem)
		mem = ft_lst_new(fd, NULL);
	tmp = mem;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
		return (ft_read(fd, line, (mem = ft_lst_new(fd, mem))));
	return (ft_read(fd, line, tmp));
}
