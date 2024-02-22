/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csan-seg <csan-seg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:46:41 by cristinasan       #+#    #+#             */
/*   Updated: 2024/02/22 12:16:05 by csan-seg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
/*actualiza la variable estática concatenando el contenido leido 
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

void	read_line(int fd, char **save, char *buf)
{
	ssize_t	read_bytes;
	char	*tmp;

	while (search_char('\n', *save) == -1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			if (*save)
				free(*save);
			*save = NULL;
			break ;
		}
		buf[read_bytes] = '\0';
		if (read_bytes == 0)
			break ;
		tmp = *save;
		*save = update_save(*save, buf);
		free(tmp);
	}
}

char	*get_final_line(char **save)
{
	char	*line;

	if (!**save)
	{
		free(*save);
		*save = NULL;
		return (NULL);
	}
	line = ft_strdup(*save);
	free(*save);
	*save = NULL;
	return (line);
}

char	*ft_getline(char **save)
{
	int		nl;
	char	*line;
	char	*tmp;

	nl = search_char('\n', *save);
	tmp = NULL;
	if (nl >= 0)
	{
		line = ft_substr(*save, 0, nl + 1);
		tmp = *save;
		*save = ft_substr (*save, nl + 1, (ft_strlen(*save) - nl - 1));
		free(tmp);
		return (line);
	}
	if (*save)
		return (get_final_line(save));
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_line(fd, &save, buf);
	free(buf);
	return (ft_getline(&save));
}
