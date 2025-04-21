/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:31:25 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/21 20:31:14 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*nbuff(char *line)
{
	char	*buf;
	char	*ptr;
	int		len;

	ptr = ft_strchr(line, '\n');
	len = (ptr - line) + 1;
	buf = ft_substr(line, 0, len);
	if (!buf)
		return (NULL);
	return (buf);
}

char	*read_buffer(int fd, char *buffer, int *byte)
{
	*byte = read(fd, buffer, BUFFER_SIZE);
	if (*byte <= 0)
		return (NULL);
	buffer[*byte] = '\0';
	return (buffer);
}

char	*process_line(char *line, char *buffer)
{
	char	*temp;

	if (!line)
		return (ft_strdup(buffer));
	temp = ft_strjoin(line, buffer);
	if (!temp)
		return (NULL);
	free(line);
	return (temp);
}

char	*rbuff(int fd, char *line)
{
	int		byte;
	char	*buffer;

	byte = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (byte > 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte <= 0)
			break ;
		buffer[byte] = '\0';
		line = process_line(line, buffer);
		if (!line || ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (byte < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*buf;

	if (fd == -1)
		return (NULL);
	if ((line && !ft_strchr(line, '\n')) || !line)
		line = rbuff(fd, line);
	if (!line)
		return (NULL);
	buf = nbuff(line);
	if (!buf)
		return (ft_free(&line));
	line = cleaner(line);
	return (buf);
}
