/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:31:25 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/10 16:57:00 by mhasoneh         ###   ########.fr       */
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

char	*cleaner(char *line)
{
	char	*new_line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(line, '\n');
	if (!ptr)
	{
		new_line = NULL;
		return (ft_free(&line));
	}
	else
		len = (ptr - line) + 1;
	if (!line[len])
		return (ft_free(&line));
	new_line = ft_substr(line, len, ft_strlen(line) - len);
	ft_free(&line);
	if (!new_line)
		return (NULL);
	return (new_line);
}

char	*rbuff(int fd, char *line)
{
	int		byte;
	char	*buffer;

	byte = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&line));
	buffer[0] = '\0';
	while (byte > 0 && !ft_strchr(buffer, '\n'))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte > 0)
		{
			buffer[byte] = '\0';
			line = ft_strjoin(line, buffer);
			if (!line)
				return (ft_free(&line));
		}
	}
	free(buffer);
	if (byte == -1)
		return (ft_free(&line));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*buf;

	if (fd < 0)
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
