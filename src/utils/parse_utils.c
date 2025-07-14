/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:12:03 by marvin            #+#    #+#             */
/*   Updated: 2025/07/10 13:12:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

int  check_blanks(char c)
{
    //si encuentra algun caracter de ESPACIO VACIO, devolver
    return (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f');
}

int  blank_space(char c)
{
    if (c != ' ' && c != '\t' && c != '\r' && c != '\n' && c != '\v' && c != '\f')
        return (-1);
    return (1);    
}

void     blank_space_map(char **file, int i, int *j)
{
    while (file[i][*j] == ' ' || file[i][*j] == '\t' || file[i][*j] == '\r' 
        || file[i][*j] == '\v' || file[i][*j] == '\f' )
        *j++;   
}

size_t  max_line_map(t_map *map, int i)
{
    size_t b_len;

    b_len = ft_strlen(map->file[i]);
    while (map->file[i])
    {
        if (ft_strlen(map->file[i]) > b_len)
            b_len = ft_strlen(map->file[i]);
        i++;
    }
    return (b_len);
}

