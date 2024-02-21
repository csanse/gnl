/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinasansegundo <cristinasansegundo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:06:25 by cristinasan       #+#    #+#             */
/*   Updated: 2024/02/20 13:48:42 by cristinasan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 1000

#endif

# include <unistd.h>
# include <stdlib.h>

size_t  ft_strlen(char *str);
char	*get_next_line(int fd);
char    *ft_substr(char const *s, unsigned int start, size_t len);

#endif