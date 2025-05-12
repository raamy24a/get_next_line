/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:31:17 by radib             #+#    #+#             */
/*   Updated: 2025/05/08 13:38:36 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_pstrlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_strjoin;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *) s2);
	if (!s2)
		return ((char *) s1);
	str_strjoin = malloc(sizeof(char) * (ft_pstrlen(s1) + ft_pstrlen(s2) + 1));
	if (!str_strjoin)
		return (NULL);
	while (s1[i++])
		str_strjoin[i - 1] = s1[i - 1];
	while (s2[j++])
	{
		str_strjoin[i - 1] = s2[j - 1];
		i++;
	}
	str_strjoin[i - 1] = '\0';
	return (str_strjoin);
}
