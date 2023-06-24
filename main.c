#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main (void)
{
	int		fd;
	char	*line;
	int		loop;

	fd = open("test.txt", O_RDONLY);
	loop = 3;
	while (loop > 0)	
	{
		line = get_next_line(fd);
		printf("%s", line);
		loop--;
	}
	return (0);
}
