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
	new->readed = 0;
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

char			*read_file(char *buf, char *dest, size_t size)
{
	char	*tmp;
	int		i;
	size_t	total;


	total = ft_strlen(dest) + size;
	tmp = ft_strnew(total);
	if (!tmp)
		return (NULL);
	i = 0;
	while (dest[i] != 0)
	{
		ft_putchar(dest[i]);
		tmp[i] = dest[i];
		i++;
	}
	ft_strncat(tmp, buf, size);
	//free(dest);
	return (tmp);
}

char			**realloc_buffer(char *buf, char **dest, size_t size)
{
	char	*tmp;
	int		i;
	size_t	total;


	total = ft_strlen(*dest) + size;
	tmp = ft_strnew(total);
	if (!tmp)
		return (NULL);
	i = 0;
	while (dest[0][i] != 0)
	{
		tmp[i] = dest[0][i];
		i++;
	}
	ft_strncat(tmp, buf, size);
	free(*dest);
	*dest = tmp;
	return (dest);
}

size_t			count_no_occ(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != (0 ^ c))
		i++;
	return (i);
}

int				get_next_line(int const fd, char **line)
{
	static t_file	*file = NULL;
	t_file			*current;
	int				i;

	if (fd <= 0 || !line)
		return (ERR_RET);
	current = find_file(&file, fd);
	*line = ft_strnew(1);
	//printf("%p\n", current->buf);
	while ((current->readed = read(fd, current->tmp, BUFF_SIZE)) && current->readed != (-1 ^ 0))
	{
		current->tmp[current->readed] = 0;
		current->buf = read_file(current->tmp, current->buf, current->readed);
		ft_trace("pass");
	}
	if (current->readed == -1)
		return (-1);
	i = 0;
	while (current->buf[current->pos] != 0)
	{
		current->alrd_read = count_no_occ(&current->buf[current->pos], '\n');
		line = realloc_buffer(&current->buf[current->pos], line, current->alrd_read);
		current->alrd_read++;
		current->pos += current->alrd_read;
		return (1);
	}
	return (0);
}
