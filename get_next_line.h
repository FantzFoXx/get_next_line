/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <udelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:50:39 by udelorme          #+#    #+#             */
/*   Updated: 2015/12/21 11:14:20 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# define ERR_RET -1

# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_file
{
	int				fd;
	int				pos;
	int				readed;
	int				alrd_read;
	char			tmp[BUFF_SIZE];
	char			*buf;
	struct s_file	*next;
}				t_file;


int				get_next_line(int const fd, char **line);

#endif
