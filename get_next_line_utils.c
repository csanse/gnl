/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinasansegundo <cristinasansegundo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:02:07 by cristinasan       #+#    #+#             */
/*   Updated: 2024/02/20 14:20:08 by cristinasan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(char *str)
{
    size_t i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *new_s;
    size_t  i;

    i = 0;
    if (!s)
        return (NULL);
    if (len > (ft_strlen((char*)s) - start) || (start > ft_strlen((char*)s)))
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
