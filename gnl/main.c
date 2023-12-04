/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinasansegundo <cristinasansegundo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:13:24 by cristinasan       #+#    #+#             */
/*   Updated: 2023/11/28 13:38:31 by cristinasan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int i;
    int fd;
    char *line;
    
    i = 0;
    fd = open("text.txt", O_RDONLY);
    while (i < 10)
    {
        line = get_next_line(fd);
        printf("%s\n", line);
        /* if (line)
            free(line); */
        i++;
    }
    return (0);
}