#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int		main(void)
{
	int fd;
	int fd2;
	char *ch;
	char *ch2;

	ch = ft_strnew(5);
	ch2 = ft_strnew(5);

	ch[0] = 'A';
	ch[1] = 'B';
	ch[2] = 'C';
	ch[3] = 'D';
	//printf("%s\n", ch);
	fd = open("test", O_RDONLY);
	fd2 = open("test2", O_RDONLY);

	if (fd != -1)
	{
		if (get_next_line(fd, &ch) != -1)
		{
			ft_putendl(ch);
			get_next_line(fd, &ch);
			ft_putendl(ch);
			get_next_line(fd, &ch);
			ft_putendl(ch);
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("error");
	close(fd);
	return (0);
}
