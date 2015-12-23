#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

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
	//fd2 = open("test2", O_RDONLY);

	//ft_nbrtrace(fd);

	if (fd != -1)
	{
		if ((ret = get_next_line(fd, &ch)) && ret != -1)
		{
			ft_nbrtrace(ret);
			ft_putendl(ch);
			ft_nbrtrace(get_next_line(fd, &ch));
			ft_putendl(ch);
			ft_nbrtrace(get_next_line(fd, &ch));
			ft_putendl(ch);
			ft_nbrtrace(get_next_line(fd, &ch));
			ft_putendl(ch);
			ft_nbrtrace(get_next_line(fd, &ch));
			ft_putendl(ch);
			ft_nbrtrace(get_next_line(fd, &ch));
			ft_putendl(ch);
			ft_nbrtrace(get_next_line(fd, &ch));
			ft_putendl(ch);
			ft_nbrtrace(get_next_line(fd, &ch));
			ft_putendl(ch);
			ft_nbrtrace(get_next_line(fd, &ch));
			ft_putendl(ch);
			ft_nbrtrace(get_next_line(fd, &ch));
			ft_putendl(ch);
			ft_nbrtrace(get_next_line(fd, &ch));
			ft_putendl(ch);
			ft_nbrtrace(get_next_line(fd, &ch));
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
