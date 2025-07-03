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



#endif