/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinasansegundo <cristinasansegundo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:46:41 by cristinasan       #+#    #+#             */
/*   Updated: 2023/11/28 13:40:39 by cristinasan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_save(char *save, char *buf)
{
	unsigned int	i;
	unsigned int	j;
	char			*newsave;

	i = 0;
	j = 0;
	newsave = malloc(sizeof(char) * (ft_strlen(save) + ft_strlen(buf) + 1));
	if (!newsave)
		return (NULL);
	if (save)
	{
		while (save[i])
		{
			newsave[i] = save[i];
			i++;
		}
	}
	while (buf[j])
	{
		newsave[i] = buf[j];
		i++;
		j++;
	}	
	newsave[i] = '\0';
	return (newsave);
}

int	search_char(char c, char *str)
{
	int	i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	read_line(int fd, char **save, char *buf)
{
	ssize_t  read_bytes;
	char	*tmp;
	while (search_char('\n', *save) == 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			*save = NULL;
			break;
		}
		buf[read_bytes] = '\0';
		if (read_bytes == 0)
			break;
		*save = update_save(*save, buf);
	}
}

char	*get_next_line(int fd)
{
	char		*line;
    static char	*save;
	char		*buf;
	
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_line(fd, &save, buf);
	
	return (save);
}