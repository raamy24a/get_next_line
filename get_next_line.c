/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:31:04 by radib             #+#    #+#             */
/*   Updated: 2025/05/13 11:18:54 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*s_dup;
	size_t	i;

	s_len = ft_pstrlen(s);
	s_dup = malloc(sizeof(char) * s_len + 1);
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

int	ft_is_strrchr_n(const char *s, char mode)
{
	char	*smot;
	size_t	i;

	if (!s)
		return (0);
	smot = (char *)s;
	i = 0;
	while (smot[i] != '\n' && smot[i])
	{
		i++;
	}
	if (smot[i] == '\n' && mode == 'b')
	{
		i++;
		return (1);
	}
	else if (smot[i] == '\n' && mode == 'a' && smot[i + 1] != '\0')
		return (1);
	return (0);
}

char	*ft_strrchr_n(const char *s, char mode)
{
	char	*smot;
	size_t	i;

	if (!s)
		return (NULL);
	smot = (char *)s;
	i = 0;
	while (smot[i] != '\n' && smot[i])
	{
		i++;
	}
	if (smot[i] == '\n' && mode == 'b')
	{
		i++;
		smot[i] = '\0';
		return (smot);
	}
	else if (smot[i] == '\n' && mode == 'a' && smot[i + 1] != '\0')
		return (smot + i + 1);
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			nbr_read;
	char		buffer[BUFFER_SIZE + 1];
	static char	*end_buffer;
	char		*temp;

	while (!ft_is_strrchr_n(end_buffer, 'b'))
	{
		if (!ft_is_strrchr_n(end_buffer, 'b'))
			nbr_read = read (fd, buffer, BUFFER_SIZE);
		if (nbr_read == 0 || nbr_read == -1)
			return (NULL);
		end_buffer = ft_strjoin(end_buffer, buffer);
	}
	temp = ft_strdup(end_buffer);
	end_buffer = ft_strrchr_n(end_buffer, 'a');
	return (ft_strrchr_n(temp, 'b'));
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("fd.txt", O_RDONLY);
	while ((line = get_next_line(fd))!= NULL)
	{
		printf("%s", line);
		i++;
	}
}