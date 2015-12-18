/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <udelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:32:02 by udelorme          #+#    #+#             */
/*   Updated: 2015/12/18 18:37:13 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static t_file	*lst_newfile(int fd)
{
	t_file *new;

	new = (t_file *)malloc(sizeof(t_file));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->readed = 0;
	new->index = 0;
	ft_memset(new->buf, 0, BUFF_SIZE);
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

int				get_next_line(int const fd, char **line)
{
	static t_file	*file = NULL;
	t_file			*bak;
	char 			*new_line;

	ft_trace("pass0");
	line = NULL;
	new_line = NULL;
	if (fd < 0 || !line)
	{
	ft_trace("pass1");
		return (ERR_RET);
	}
	ft_trace("pass12");
	bak = file;
	while (fd != file->fd && file)
		file = file->next;
	if (!file)
	{
		lst_pushfile(&file, fd);
		bak = file;
	}
	
	while (read(fd, file->buf, BUFF_SIZE))
	{
		while (file->buf[file->readed] != ('\n' ^ 0))
		{
			ft_trace("pass4");
		}
	}
	return (0);
}
