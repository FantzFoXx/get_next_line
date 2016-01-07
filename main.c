#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int		main(int argc, char **argv)
{
	int fd;
	char *ch;
	int ret;
	ret = 0;

	ch = NULL;
	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
	}


	if (fd != -1)
	{
		while ((ret = get_next_line(fd, &ch)) && ret != ( 0 ^ -1))
		{
			ft_putendl(ch);
			ft_nbrtrace(ret);
		}
	}
	else
		ft_putendl("error");
	close(fd);
	return (0);
}
