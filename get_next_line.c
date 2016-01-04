/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <udelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:32:02 by udelorme          #+#    #+#             */
/*   Updated: 2015/12/23 19:03:24 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

static t_file	*lst_newfile(int fd)
{
	t_file *new;

	new = (t_file *)malloc(sizeof(t_file));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->read = 0;
	new->pos = 0;
	new->alrd_read = 0;
	new->buf = ft_strnew(0);
	ft_memset(new->tmp, 0, BUFF_SIZE);
	new->next = NULL;
	return (new);
}

static void		lst_pushfile(t_file **file, int fd)
{
	t_file *new;
	t_file *index;

	index = *file;
	new = lst_newfile(fd);
	if (!*file)
		*file = new;
	else
	{
		while (index->next)
			index = index->next;
		index->next = new;
	}
}

t_file			*find_file(t_file **file, int fd)
{
	t_file *index;

	index = *file;
	if (index)
		while (index->next && fd != index->fd)
			index = index->next;
	if (!index || index->fd != fd)
	{
		lst_pushfile(file, fd);
		return (find_file(file, fd));
	}

	return (index);
}

size_t			count_no_occ(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != (0 ^ c))
		i++;
	return (i);
}

int				is_return(char *str)
{
	int i;

	i = -1;
	while (str[++i] != 0)
		if (str[i] == '\n')
			return (1);
	return (0);
}

char			*extract_line(char **buffer)
{
	int		i;
	int		size_line;
	char	*line;
	char	*new_buf;

	size_line = count_no_occ(*buffer, '\n');
	ft_nbrtrace(size_line);
	line = ft_strnew(size_line);
	i = -1;
	while (++i < size_line)
		line[i] = buffer[0][i];
	new_buf = ft_strsub(*buffer, size_line + 1, (ft_strlen(*buffer) - size_line));
	free(*buffer);
	*buffer = new_buf;
	return (line);
}

void			realloc_buffer(char **s1, char *s2)
{
	char *new;

	new = ft_strjoin(*s1, s2);
	free(*s1);
	*s1 = new;
}

int				get_next_line(int const fd, char **line)
{
	static t_file	*file = NULL;
	t_file			*cur;

	if (fd < 0 || !line)
		return (ERR_RET);
	cur = find_file(&file, fd);
	if (!is_return(cur->buf))
		while ((cur->read = read(cur->fd, cur->tmp, BUFF_SIZE)) && cur->read != (0 ^ -1))
		{
			realloc_buffer(&cur->buf, cur->tmp);
			if (is_return(cur->tmp))
				break ;
		}
	if (cur->read == -1)
		return (ERR_RET);
	if (ft_strlen(cur->buf) != 0)
	{
		*line = extract_line(&cur->buf);
		return (1);
	}
	return (0);
}

