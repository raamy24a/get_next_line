/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:31:04 by radib             #+#    #+#             */
/*   Updated: 2025/05/12 12:52:01 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif

char	*ft_strrchr_n(const char *s)
{
	char			*smot;
	size_t			i;

	smot = (char *)s;
	i = 0;
	while (smot[i] != '\n' && smot[i])
	{
		i++;
	}
	if (smot[i] == '\n')
	{
		i++;
		smot[i] = '\0';
		return (smot);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			nbr_read;
	static char	buffer[BUFFER_SIZE + 1];
	char		*ptr;
	int			i;

	i = 0;
	while (nbr_read != 0)
	{
		nbr_read = read(fd, buffer, BUFFER_SIZE);
		if (nbr_read == -1 || nbr_read == 0)
			return (NULL);
		if (nbr_read > 0)
			buffer[nbr_read] = '\0';
		if (ft_strrchr_n(buffer))
		{
			ptr = ft_strjoin(ptr, ft_strrchr_n(buffer));
			return (ptr);
		}
		else
			ptr = ft_strjoin(ptr, buffer);
		i++;
	}
	return (ptr);
}

int	main(void)
{
	int	fd;

	fd = open("fd.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}