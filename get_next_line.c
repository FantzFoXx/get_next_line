/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <udelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:32:02 by udelorme          #+#    #+#             */
/*   Updated: 2016/01/06 19:21:38 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void		lst_pushfile(t_file **file, int fd)
{
	t_file *new;
	t_file *index;

	index = *file;
	new = (t_file *)malloc(sizeof(t_file));
	if (new)
	{
		new->fd = fd;
		new->read = 0;
		new->buf = ft_strnew(0);
		ft_memset(new->tmp, 0, BUFF_SIZE);
		new->next = NULL;
		if (!*file)
			*file = new;
		else
		{
			while (index->next)
				index = index->next;
			index->next = new;
		}
	}
}

static t_file	*find_file(t_file **file, int fd)
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
/*
   static int		extract_line(char **buffer, int read, char **line)
   {
   int		i;
   int		size_line;
   char	*new_buf;

   size_line = 0;
   while (buffer[0][size_line] != 0)
   {
   if (buffer[0][size_line] == '\n')
   break ;
   size_line++;
   }
 *line = ft_strnew(size_line);
 i = -1;
 while (++i < size_line)
 line[0][i] = buffer[0][i];
 new_buf = ft_strsub(*buffer, size_line + 1,
 (ft_strlen(*buffer) - i));
 free(*buffer);
 *buffer = new_buf;
 if (ft_strlen(*buffer) != 0 && read != 0)
 return (1);
 else
 return (0);
 return (0);
 }
 */
static int		extract_line(char **buffer, int read, char **line)
{
	size_t		size_line;
	char		*new_buf;
	int			ret;

	size_line = -1;
	ret = 0;
	//while (buffer[0][++size_line] != (0 ^ '\n'));
	while (buffer[0][++size_line] != 0)
	{
		if (buffer[0][size_line] == '\n')
			break ;
	}
	*line = ft_strnew(size_line);
	ft_strncpy(*line, *buffer, size_line);
	if ((ft_strlen(*buffer) != 0 || read != 0))
		ret = 1;
	new_buf = ft_strsub(*buffer, size_line + 1,
			(ft_strlen(*buffer) - size_line));
	free(*buffer);
	//ft_trace("free 2");
	*buffer = (char*)malloc((ft_strlen(new_buf) + 1) * sizeof(char));
	ft_strcpy(*buffer,new_buf);
	free(new_buf);
	//ft_trace("free 3");
	//printf("a la sortie d'extract, line vaut %s, buffer vaut %s\n",*line,*buffer);
	return (ret);
}

static char		*realloc_buffer(char **s1, char *s2)
{
	char *new;

	new = ft_strjoin(*s1, s2);
	if (!new)
		return (NULL);
	//printf("avant l'incident, la taille de s1 est %d et s1 contient %s\n",(int)ft_strlen(*s1),*s1);
	free(*s1);
	//printf("la taille de new est %d\n",(int)ft_strlen(new));
	//write(1, *s1, 5);
	*s1 = ft_strnew(ft_strlen(new));
	ft_strcpy(*s1,new);
	free(new);
	//ft_trace("free 1");
	return (*s1);
}

int				get_next_line(int const fd, char **line)
{
	static t_file	*file = NULL;
	t_file			*cur;
	//char			*buf_cpy;

	cur = find_file(&file, fd);
	printf("cur buf contient %s\n",cur->buf);
	printf("l'adresse de cur->buf %p\n",&cur->buf);

	if (!ft_strchr(cur->buf, '\n') /*|| ft_strlen(cur->buf) == 1*/)
		while ((cur->read = read(cur->fd, cur->tmp, BUFF_SIZE))
				&& cur->read != (0 ^ -1))
		{
			cur->tmp[cur->read] = 0;
			//buf_cpy = cur->buf;
			//printf("avant le realloc, cur buf vaut %s\n",cur->buf);
			if (!(realloc_buffer(&cur->buf, cur->tmp)))
				return (ERR_RET);
			//cur->buf = buf_cpy;
			//printf("cur->buf vaut %s\n",cur->buf);
			if (ft_strchr(cur->tmp, '\n'))
			  {
			    //printf("BOUM\n");
				break ;
			  }
		}
	if (cur->read == -1 || !line)
		return (ERR_RET);
	if (ft_strlen(cur->buf) != 0)
		return(extract_line(&cur->buf, cur->read, line));
	return (0);
}
