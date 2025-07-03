/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:10:31 by marvin            #+#    #+#             */
/*   Updated: 2025/07/03 09:10:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

static int  check_map_elements(t_general *gen, char **map)
{
    int     i;
    int     j;
    
    i = 0;
    //iniciamos la localizacion de player como 0;
    gen->pl->loc = '0';
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j])
        {
            //check de espacio en blanco
            while (check_blanks(map[i][j]))
                j++;
            if (!ft_strchr("10NSWE", map[i][j]))
                printf("Error\n");
            if (ft_strchr("NSWE", map[i][j]) && gen->pl->loc != '0')
                printf("Error\n");
            if (ft_strchr("NSWE", map[i][j]) && gen->pl->loc == '0')
                gen->pl->loc = map[i][j];
            j++;
        }
        i++;
    }
    return (0);
}

static int  check_position_is_valid(t_general *gen, char **map)
{
    int i;
    int j;
    int k;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    i = gen->pl->pos_x;
    j = gen->pl->pos_y;
    k = 0;
    
    while (k < 4)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni < 0 || nj < 0 || map[i] == NULL || nj >= (int)ft_strlen(map[ni]))
            return (1);
        if (is_a_blank_space(map[ni][nj] == 0))
            return (1);
    }
    return (0);
}

static int check_position_player(t_general *gen, char **map)
{
    int     i;
    int     j;

    if (gen->pl->loc == '0')
        prinf("ERROR\n");
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (ft_strchr("NSWE", map[i][j]))
            {
                gen->pl->pos_x = i;
                gen->pl->pos_y = j;
                map[i][j] = '0';
            }
            j++;
        }
        i++;
    }
    if (check_position_is_valid(gen, map) == 1)
        printf("Error\n");
    return (0);
}

static int  check_end_map(t_map *s_map, char **map)
{
    int     i;
    int     j;

    i = s_map->end_map;
    while (s_map->file[i][j])
    {
        j = 0;
        while (s_map->file[i][j])
        {
            if (check_blanks_end(map[i][j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_map_valid(t_general *gen, char **map)
{
    if (!gen->map)
        //ERROR
    if (check_map_elements(gen, map))
        //error
    if (check_position_player(gen, map))
        //error
    if (check_end_map(&gen->s_map, map))
        //error
    return (0);
}