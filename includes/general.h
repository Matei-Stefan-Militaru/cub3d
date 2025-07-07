/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:22:10 by pmorello          #+#    #+#             */
/*   Updated: 2025/06/30 22:25:07 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
#define GENERAL_H

#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include "images.h"
#include "textures.h"
#include "player.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <stdbool.h>

typedef struct s_general
{
    void    *mlx; //puntero a MLX
    void    *win; //puntero para referenciar la ventana
    int     win_heigth; //altura de WIN
    int     win_width; //anchura de WIN
    char    **map; //para guardar el MAPA

    int     **textures; //doble puntero, donde guardar las texturas de las paredes
    int     **text_pixels;

    t_image *img; //puntero al STRUCT de IMAGE
    t_texture *text; //puntero a la STRUCT de TEXTURE
    t_player *pl; //puntero a la STRUCT de PLAYER
    t_map   *s_map; //puntero a la STRUCT de MAP
    
} t_general;

#endif