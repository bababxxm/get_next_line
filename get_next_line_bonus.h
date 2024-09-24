/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:11:48 by sklaokli          #+#    #+#             */
/*   Updated: 2024/09/24 19:13:41 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*get_buffer(int fd, char *buffer);
char	*ft_free(char *buffer, char *tmp);
char	*get_one_line(char *buffer);
char	*get_leftover(char *buffer);

int		ft_strlen(char *s);
int		newline_found(char *line);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *buffer, char *tmp);

#endif
