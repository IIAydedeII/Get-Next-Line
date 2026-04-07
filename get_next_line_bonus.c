/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:07:24 by adede             #+#    #+#             */
/*   Updated: 2026/04/05 18:06:54 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*cleanup(char *stash, char *buffer)
{
	free(stash);
	free(buffer);
	return (NULL);
}

static char	*read_and_stash(int fd, char *stash)
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
		if (!stash)
			return (cleanup(NULL, buffer));
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	char		*line;
	char		*newline;
	size_t		len;

	if (!stash || !stash[0])
		return (NULL);
	newline = ft_strchr(stash, '\n');
	if (newline)
		len = newline - stash + 1;
	else
		len = ft_strlen(stash);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, len);
	line[len] = '\0';
	return (line);
}

static char	*remove_extracted_line(char *stash)
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
	static char	*stashes[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (NULL);
	stashes[fd] = read_and_stash(fd, stashes[fd]);
	if (!stashes[fd])
		return (NULL);
	line = extract_line(stashes[fd]);
	stashes[fd] = remove_extracted_line(stashes[fd]);
	return (line);
}
