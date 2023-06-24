#include <stdio.h>

#include "get_next_line.h"

char	*get_current_line(char *accumulator)
{
	char	*current_line;
	char	*next_line;
	int		count;
	int		count_nl;

	current_line = accumulator;
	// count = ft_strlen(accumulator);
	while (accumulator[count] && accumulator[count] != '\n')
	{
		current_line[count] = accumulator[count];
		count++;
	}
	current_line[count] = '\n';
	count++;
	count_nl = 0;
	next_line = malloc(ft_strlen(accumulator) - count);
	while (accumulator[count] != '\0')
	{
		next_line[count_nl] = accumulator[count];
		count_nl++;
		count++;
	}
	current_line[count + 1] = '\0';
	// printf("count: %i\n", count); //APAGAR!
	printf("current line: %s\n", current_line); //APAGAR!
	accumulator = next_line;
	printf("accumulator: %s\n", accumulator); //APAGAR!
	return (current_line);
}

void	read_buffer(int fd, char *accumulator)
{
	char	*buffer;
	char	read_bytes;
	int		i; //APAGAR!

	buffer = malloc(BUFFER_SIZE + 1);
	read_bytes = 1;
	i = 1;
	while (!ft_strchr(buffer, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		printf("buffer %i: %s\n", i, buffer); //APAGAR!
		accumulator = ft_strjoin(accumulator, buffer);
		// printf("accumulator %i: %s\n", i, accumulator); //APAGAR!
		i++; //APAGAR!
	}

	printf("\n\n-- final --\n"); //APAGAR!
	printf("buffer: %s\n", buffer); //APAGAR!
	// printf("accumulator: %s\n", accumulator); //APAGAR!
	get_current_line(accumulator);
}

char *get_next_line(int fd)
{
	static char	*accumulator;

	accumulator = malloc(BUFFER_SIZE + 1);
	read_buffer(fd, accumulator);
	return (0);
}
