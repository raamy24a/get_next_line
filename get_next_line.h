/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:01:40 by radib             #+#    #+#             */
/*   Updated: 2025/05/14 16:52:49 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

size_t	ft_pstrlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_strrchr_and_free(char *end_buffer, char mode);
char	*ft_strrchr_a(char *s);
char	*ft_strrchr_b(char *s);
char	*ft_strdup(const char *s);

#endif