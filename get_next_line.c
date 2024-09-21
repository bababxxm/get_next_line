/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:10:10 by sklaokli          #+#    #+#             */
/*   Updated: 2024/09/21 23:54:45 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_line(char *buffer)
// {
// 	// int		i;
// 	int		size;
// 	char	*line;

// 	if (buffer == NULL)
// 		return (NULL);
// 	size = 0;
// 	while (buffer[size] != '\n' && buffer[size] != '\0')
// 		size++;
// 	line = (char *)malloc(size + 2);
// 	if (line == NULL)
// 		return (NULL);
// 	// i = -1;
// 	// while (buffer[++i] && i < size)
// 	// 	line[i] = buffer[i];
// 	// if (buffer[i] == '\n')
// 	// 	line[i] = '\n';
// 	// else if (buffer[i] == '\0')
// 	// 	line[i] = '\0';
// 	if (buffer[size] == '\n')
// 	{
// 		line[size + 1] = '\0';
// 		line[size] = '\n';
// 	}
// 	else if (buffer[size] == '\0')
// 		line[size] = '\0';
// 	while (size--)
// 		line[size] = buffer[size];
// 	// if (buffer[size] == '\0')
// 	// {
// 	// 	line[size] = '\0';
// 	// 	while (size--)
// 	// 		line[size] = buffer[size];
// 	// }
// 	// else if (buffer[size] == '\n')
// 	// {
// 	// 	line[size] = '\n';
// 	// 	while (size--)
// 	// 		line[size] = buffer[size];
// 	// }
// 	return (line);
// }

char	*get_line(char *buffer)
{
	int		size;
	char	*line;
	
	if (!buffer)
		return (NULL);
	size = 0;
	while (buffer[size])
	{
		if (buffer[size] == '\n')
		{
			size++;
			break ;
		}
		size++;
	}
	line = (char *)malloc(size + 1);
	if (!line)
		return (NULL);
	line[size] = '\0';
	while (size--)
		line[size] = buffer[size];
	return (line);
}
char	*get_next(char *buffer)
{
	int		i;
	int		j;
	char	*next;

	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	next = (char *)malloc((int)ft_strlen(buffer) - i + 1);
	if (next == NULL)
		return (NULL);
	j = 0;
	while (buffer[i++])
		next[j++] = buffer[i];
	next[j] = '\0';
	return (next);
}

char	*get_buffer(int fd, char *buffer)
{
	int		byte;
	char	*res;

	byte = 1;
	res = (char *)malloc(1);
	if (buffer != NULL)
		res = ft_strjoin(res, buffer);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL || res == NULL)
		return (NULL);
	while (byte > 0 && !ft_strchr(buffer, '\n'))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(res);
			free(buffer);
			return (NULL);
		}
		buffer[byte] = '\0';
		res = ft_strjoin(res, buffer);
	}
	free (buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_buffer(fd, buffer);
	line = get_line(buffer);
	buffer = get_next(buffer);
	return (line);
}

// int	main()
// {
// 	int fd = open("./text.txt", O_RDONLY);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	int i = 1;
// 	char *line;
// 	while (i <= LINE)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		printf("%s", line);
// 		i++;
// 	}
// 	close(fd);
// }
