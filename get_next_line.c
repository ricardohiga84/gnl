#include "get_next_line.h"
#include <stdio.h> //APAGAR!!!

char	*split_accumulator(char *accumulator)
{
	int		count;
	char	*current_line;
	//char	*next_line;

	current_line = malloc(sizeof(accumulator + 2));
	count = 0;
	while (accumulator[count] && accumulator[count] != '\n')
	{
		current_line[count] = accumulator[count];
		count++;
	}
	current_line[count] = '\n';
	current_line[count + 1] = '\0';
	//printf("%s", current_line);
	return (current_line);
}

char	*read_buffer(int fd, char *accumulator)
{
	char	*current_buffer;
	int		file_return;
	int		i = 1; //TESTE

	current_buffer = malloc(BUFFER_SIZE + 1);
	current_buffer = accumulator;
	file_return = 1;
	while (!ft_strchr(accumulator, '\n') && file_return > 0)
	{
		accumulator = ft_strjoin(accumulator, current_buffer);
		file_return = read(fd, current_buffer, BUFFER_SIZE);
		//current_buffer[file_return] = '\0';
		//printf("buffer %i: %s\n", i, current_buffer);
		//printf("accumulator: %s\n", accumulator);
		i++;
	}
	return (accumulator);
}

char	*get_next_line(int fd)
{
	char	*accumulator;
	char	*line;
	
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	accumulator = malloc(BUFFER_SIZE + 1);
	if (!accumulator)
		return (NULL);
	accumulator = read_buffer(fd, accumulator);
	//printf("accumulator: %s\n", accumulator);
	//line = malloc(sizeof(accumulator) + 2);
	line = split_accumulator(accumulator);
	return (line);
}
