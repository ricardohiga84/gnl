#include "get_next_line.h"
#include <stdio.h> //APAGAR!!!

char	*save_next_line(char *accumulator)
{
	char	*next_line;
	size_t	count_acc;
	size_t	count_next_line;

	count_acc = 0;
	count_next_line = 0;
	while (accumulator[count_acc] != '\n' && accumulator[count_acc])
		count_acc++;
	if (!accumulator[count_acc])
	{
		free(accumulator);
		return (NULL);
	}
	next_line = ft_calloc(ft_strlen(accumulator) - count_acc + 1, sizeof(char));
	count_acc++;
	while (accumulator[count_acc])
		next_line[count_next_line++] = accumulator[count_acc++];
	free(accumulator);
	return (next_line);
}

char	*get_current_line(char *accumulator)
{
	char	*line;
	size_t	count;

	count = 0;
	if (!accumulator[count])
		return (NULL);
	while (accumulator[count] != '\n' && accumulator[count])
		count++;
	line = ft_calloc(count + 2, sizeof(char));
	count = 0;
	while (*accumulator != '\n' && *accumulator)
		line[count++] = *accumulator++;
	if (*accumulator == '\n')
		line[count] = '\n';
	return (line);
}

char	*read_buffer(int fd, char *accumulator)
{
	char	*buffer;
	char	*temp_buffer;
	ssize_t	read_bytes;

	if (!accumulator)
		accumulator = ft_calloc(1, sizeof(char));
	temp_buffer = accumulator;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_bytes = 1;
	while (!ft_strchr(accumulator, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(temp_buffer);
			return(NULL);
		}
		if (read_bytes == 0)
			break;
		buffer[read_bytes] = '\0';
		temp_buffer = accumulator;
		accumulator = ft_strjoin(temp_buffer, buffer);
		free(temp_buffer);
	}
	free(buffer);
	return (accumulator);
}

char	*get_next_line(int fd)
{
	static char	*accumulator;
	char		*line;
	
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	accumulator = read_buffer(fd, accumulator);
	if (!accumulator)
		return (NULL);
	line = get_current_line(accumulator);
	accumulator = save_next_line(accumulator);
	return (line);
}
