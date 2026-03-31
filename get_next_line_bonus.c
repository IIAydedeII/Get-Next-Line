/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:07:24 by adede             #+#    #+#             */
/*   Updated: 2026/03/31 14:02:24 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*cleanup(char *stash, char *buffer)
{
	free(stash);
	free(buffer);
	return (NULL);
}

char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	char	*tmp;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while ((!stash || !ft_strchr(stash, '\n')) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (cleanup(stash, buffer));
		buffer[bytes] = '\0';
		tmp = stash;
		if (!stash)
			stash = ft_strdup(buffer);
		else
			stash = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	free(buffer);
	return (stash);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, i);
	line[i] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	char	*new_stash;
	char	*newline;

	if (!stash)
		return (NULL);
	newline = ft_strchr(stash, '\n');
	if (!newline)
		return (cleanup(stash, NULL));
	new_stash = ft_strdup(newline + 1);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
