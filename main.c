#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main (void)
{
	int		fd;
	char	*line;
	int		loop;
	int		i;

	fd = open("test.txt", O_RDONLY);

	// line = get_next_line(fd);
	// printf("%s", line);

	loop = 2;
	i = 1;
	while (i <= loop)
	{
		printf("--- call %i ---\n", i);
		line = get_next_line(fd);
		i++;
	}
	return (0);
}
