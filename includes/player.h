/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:19:35 by marvin            #+#    #+#             */
/*   Updated: 2025/07/03 09:19:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H

#include "../mlx/mlx.h"

typedef struct s_player
{
    char    exist; //para si hay PLAYER
    int     pos_x; //posicion X de player
    int     pos_y; //posicion Y de player

} t_player;

#endif