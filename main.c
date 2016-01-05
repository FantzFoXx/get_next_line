#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int fd;
	int fd2;
	char *ch;
	char *ch2;
	int ret;
	ret = 0;

	ch = NULL;
	ch2 = NULL;
	fd = 0;
	fd2 = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open("mult", O_RDONLY);
	}
	//fd2 = open("test2", O_RDONLY);

	//ft_nbrtrace(fd);

	if (fd != -1)
	{
		while ((ret = get_next_line(fd, &ch)) && ret != ( 0 ^ -1))
		{
			ft_putendl(ch);
			get_next_line(fd2, &ch2);
			ft_putendl(ch2);
		}
			//ft_nbrtrace(ret);
	}
	else
		ft_putendl("error");
	close(fd);
	return (0);
}
