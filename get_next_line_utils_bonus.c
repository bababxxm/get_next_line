/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:11:38 by sklaokli          #+#    #+#             */
/*   Updated: 2024/09/24 19:12:50 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	newline_found(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	res = (char *)malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (s[++i])
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	s += start;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *buffer, char *tmp)
{
	int		i;
	char	*res;

	if (!buffer && !tmp)
		return (NULL);
	if (!buffer || !tmp)
		return (ft_strdup(tmp));
	res = (char *)malloc(ft_strlen(buffer) + ft_strlen(tmp) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (*buffer)
		res[i++] = *buffer++;
	while (*tmp)
		res[i++] = *tmp++;
	res[i] = '\0';
	return (res);
}
