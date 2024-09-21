#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*copy_line(const char *buffer, size_t len)
{
	char	*line = (char *)malloc(len + 1);
	size_t	i;

	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[len] = '\0';  // Null-terminate the line
	return (line);
}

char	*shift_buffer(char *buffer, size_t start)
{
	size_t	i = 0, len = ft_strlen(buffer);

	while (start < len)
		buffer[i++] = buffer[start++];
	buffer[i] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;
	size_t		line_len;
	char		*newline_pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	// Read data into buffer if there's no newline
	while (!(newline_pos = ft_strchr(buffer, '\n')))
	{
		bytes_read = read(fd, buffer + ft_strlen(buffer), BUFFER_SIZE - ft_strlen(buffer));
		if (bytes_read < 0)  // Handle read error
			return (NULL);
		if (bytes_read == 0)  // End of file reached
			break;
		buffer[bytes_read] = '\0';
	}

	// Handle case where buffer doesn't have a newline and no more data to read
	if (!*buffer)
		return (NULL);

	// Calculate the line length (either up to newline or the whole buffer)
	if (newline_pos)
		line_len = newline_pos - buffer + 1;
	else
		line_len = ft_strlen(buffer);

	// Copy the line from buffer
	line = copy_line(buffer, line_len);
	if (!line)
		return (NULL);

	// Shift the remaining data in the buffer to the beginning
	if (newline_pos)
		shift_buffer(buffer, line_len);
	else
		buffer[0] = '\0';  // Clear the buffer if no more data

	return (line);
}
