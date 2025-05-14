/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:31:04 by radib             #+#    #+#             */
/*   Updated: 2025/05/14 17:11:06 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*s_dup;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_pstrlen(s);
	s_dup = malloc(sizeof(char) * (s_len + 1));
	if (!s_dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_dup[i] = s[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}

static int	has_newline(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_file(int fd, char *stash)
{
	char	*buffer;
	char	*temp;
	int		nbr_read;

	nbr_read = 1;
	while (!has_newline(stash) && nbr_read > 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		nbr_read = read(fd, buffer, BUFFER_SIZE);
		if (nbr_read < 0)
		{
			free(buffer);
			if (stash)
				free(stash);
			return (NULL);
		}
		buffer[nbr_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(buffer);
		free(stash);
		stash = temp;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*new_stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	if (stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_strrchr_b(stash);
	new_stash = ft_strrchr_a(stash);
	free(stash);
	stash = new_stash;
	return (line);
}
