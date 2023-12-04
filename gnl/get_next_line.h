/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinasansegundo <cristinasansegundo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:06:25 by cristinasan       #+#    #+#             */
/*   Updated: 2023/11/28 13:28:05 by cristinasan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 42

#endif

# include <unistd.h>
# include <stdlib.h>

size_t  ft_strlen(char *str);
char	*get_next_line(int fd);

#endif