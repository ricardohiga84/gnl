#include "get_next_line.h"
#include <stdio.h> //APAGAR!!!

char	*split_accumulator(char *accumulator)
{
	char	*current_line;
	char	*next_line;
	int		count;
	// int		line;

	// current_line = malloc(1);
	count = 0;
	while (accumulator[count] && accumulator[count] != '\n')
	{
		current_line[count] = accumulator[count];
		count++;
	}
	current_line[count] = '\n';
	next_line = ft_strchr(accumulator, '\n');
	accumulator = next_line;
	// printf("current_line: %s\n", current_line);
	printf("accumulator split: %s\n", accumulator);
	return (current_line);
}

char	*read_buffer(int fd, char *accumulator)
{
	char	*current_buffer;
	int		file_return;
	int		i; //APAGAR!!

	current_buffer = malloc(BUFFER_SIZE + 1);
	// current_buffer = accumulator;
	file_return = 1;
	i = 0;
	while (!ft_strchr(accumulator, '\n') && file_return > 0)
	{
		accumulator = ft_strjoin(accumulator, current_buffer);
		file_return = read(fd, current_buffer, BUFFER_SIZE);
		current_buffer[file_return] = '\0';
		// printf("accumulator: %s\n", accumulator);
		i++;
	}
	free(current_buffer);
	return (accumulator);
}

char	*get_next_line(int fd)
{
	static char	*accumulator;
	char		*line;
	
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
		if (!accumulator)
		accumulator = malloc(BUFFER_SIZE + 1);
	if (!accumulator)
		return (NULL);
	accumulator = read_buffer(fd, accumulator);
	line = split_accumulator(accumulator);
	// printf("accumulator gnl: %s\n", accumulator);
	return (line);
}
