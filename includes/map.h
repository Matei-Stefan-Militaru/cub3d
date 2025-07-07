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
    int     fd; //file descriptor
    int     line_count; //cuantas lineas tiene el MAPA
    char    *path; //donde esta guardado el MAPA
    char    **file; //para saber el contenido del MAPA, linea por linea.
    int     height; //alargada del MAPA
    int     width; //amplitud del MAPA
    int     end_map; //punto para saber si se ha llegado al final del MAPA.

} t_map;
 
#endif