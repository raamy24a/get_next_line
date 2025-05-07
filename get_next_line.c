/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:31:04 by radib             #+#    #+#             */
/*   Updated: 2025/05/07 17:26:17 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif

char	*get_next_line(int fd)
{
	size_t		nbr_read;
	static char	buffer[BUFFER_SIZE + 1];
	char		*ptr;


	nbr_read = read(fd, buffer, BUFFER_SIZE);
	if (nbr_read == -1 || nbr_read == 0)
		return (NULL);
	if (buffer && nbr_read > 0)
		buffer[nbr_read] = '\0';
	ptr = buffer;
	while (*ptr++ != '\n' && *ptr++)
		{
			if (*ptr == '\n')
				return (full_line);
		}
}
