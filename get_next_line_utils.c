/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csan-seg <csan-seg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:02:07 by cristinasan       #+#    #+#             */
/*   Updated: 2024/02/21 14:29:21 by csan-seg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > (ft_strlen((char*)s) - start)
	|| (start > ft_strlen((char*)s)))
		return (NULL);
	new_s = malloc(sizeof(char) * len + 1);
	if (!new_s)
		return (NULL);
	while (i < len)
	{
		new_s[i] = s[start];
		i++;
		start++;
	}
	new_s[i]= '\0';
	return (new_s);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dst;

	if (!str)
		return (NULL);
	dst = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (str[++i])
		dst[i] = str[i];
	dst[i] = '\0';
	return (dst);
}
int	search_char(char c, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}