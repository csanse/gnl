/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinasansegundo <cristinasansegundo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:46:41 by cristinasan       #+#    #+#             */
/*   Updated: 2024/02/20 14:36:27 by cristinasan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
/* actualiza la variable estática concatenando el contenido leido 
parametros: 
		buf: lo qe he leido
		save: estatica que guarda lo que he leido */
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
		free(save);
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
char	*ft_strdup(char *str)
{
	int	i;
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

void	read_line(int fd, char **save, char *buf)
{
	ssize_t  read_bytes;
	while (search_char('\n', *save) == -1)
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
	int			nl;
	char		*tmp;
	
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_line(fd, &save, buf);
	free(buf);
	nl = search_char('\n', save);
	if (nl >= 0)
	{
		line = ft_substr(save, 0, nl);
		tmp = save;
		save = ft_substr (save, nl + 1, (ft_strlen(save) - nl - 1));
		free (tmp);
		return (line);
	}
	if (save)
	{
		line = ft_strdup(save);
		free(save);
		save = NULL;
		return (line);	
	}
	return (NULL);
}
