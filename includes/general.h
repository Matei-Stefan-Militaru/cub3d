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

typedef struct s_general
{
    void    *mlx; //puntero a MLX
    void    *win; //puntero para referenciar la ventana
    int     win_heigth; //altura de WIN
    int     win_width; //anchura de WIN
    char    **map; //para guardar el MAPA

    int     **textures; //doble puntero, donde guardar las texturas de las paredes

    t_image *img; //puntero al STRUCT de IMAGE
    t_texture *text; //puntero a la STRUCT de TEXTURE
    t_player *pl; //puntero a la STRUCT de PLAYER
    t_map   *s_map; //puntero a la STRUCT de MAP
    
} t_general;

//INIT GENERAL
void    init_general(t_general *gen);
void    init_images_params(t_image *img);
void    init_text_params(t_texture *text);

//INIT MLX
void    init_mlx(t_general *gen);
void    init_img(t_general *gen, t_image *img, int width, int heigth);
void    init_textures_img(t_general *gen, t_image *img, char *path);

//INIT TEXTURES
void    init_textures(t_general *gen);


//PARSE
static int  check_map_elements(t_general *gen, char **map);
static int  check_blanks(char c);
static int  check_blanks_end(char c);

#endif