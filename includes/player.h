/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:19:35 by marvin            #+#    #+#             */
/*   Updated: 2025/07/09 15:43:20 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H

#include "../mlx/mlx.h"

typedef struct s_player
{
    char    exist; //marca para saber si hay PLAYER en el MAPA
    char    dir; //marca para saber que orientacion estara en PLAYER en el MAPA (N,S,E,W)
    double  dir_x; //marca la direccion donde estara mirando el PLAYER, en el eje X, del MAPA
    double  dir_y; //marca la direccion donde estara mirando el PLAYER, en el eje Y, del MAPA
    double  pos_x; //marca la posicion de PLAYER, en el eje X, del MAPA
    double  pos_y; //marca la posicion de PLAYER, en el eje Y, del MAPA
    double  plane_x; //marca el plano de camara del PLAYER, en el eje X
    double  plane_y; //marca el plano de camara del PLAYER, en el eje Y
    double  s_rotate; //marca la velocidad de rotacion de PLAYER
    int     move_x; //indica si PLAYER esta MOVIENDO en el eje X
    int     move_y; //indica si PLAYER esta moviendo en el eje Y
    int     rotate; //indica si PLAYER esta ROTANDO

} t_player;


#endif