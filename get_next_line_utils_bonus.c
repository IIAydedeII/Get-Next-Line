/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:09:39 by adede             #+#    #+#             */
/*   Updated: 2026/03/31 14:02:34 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_casted;
	unsigned char	*src_casted;
	size_t			i;

	if (dest == src)
		return (dest);
	dest_casted = (unsigned char *)dest;
	src_casted = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_casted[i] = src_casted[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*strjoin;
	char	*start;

	if (!s1 || !s2)
		return (NULL);
	strjoin = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	start = strjoin;
	while (*s1)
		*strjoin++ = *s1++;
	while (*s2)
		*strjoin++ = *s2++;
	*strjoin = '\0';
	return (start);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	buff_len;

	buff_len = ft_strlen(s) + 1;
	dup = malloc(buff_len * sizeof(char));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, buff_len);
	return (dup);
}
