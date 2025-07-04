/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:32:39 by marvin            #+#    #+#             */
/*   Updated: 2025/07/03 11:32:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include "../mlx/mlx.h"

typedef struct s_map
{
    int     fd;
    int     line_count;
    char    *path;
    char    **file;
    int     height;
    int     width;
    int     end_map;

} t_map;

//PARSE
/*
static int  map_elements(t_general *gen, char **map);
static int  map_position(t_general *gen, char **map);
static int  map_player_pos(t_general *gen, char **map);
static int  map_end(t_map *s_map, char **map);
static int  map_top(char **map, int i);
static int  map_sides(t_map *s_map, char **map);
*/
int check_map(t_general *gen, char **map);
int  check_blanks(char c);
int  blank_space(char c);
 
#endif