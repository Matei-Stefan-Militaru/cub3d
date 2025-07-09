/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:22:10 by pmorello          #+#    #+#             */
/*   Updated: 2025/07/09 15:52:01 by pmorello         ###   ########.fr       */
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
#include <X11/X.h>
#include <X11/Xlib.h>

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


//general
void    init_general(t_general *gen);
void    init_map_params(t_map *map);
void    init_textures_params(t_texture *text);
void    init_player_params(t_player *player);
void    init_images_params(t_image *img);
void    init_text_params(t_texture *text);

//mlx
void    init_mlx(t_general *gen);

//images
void    init_img(t_general *gen, t_image *img, int width, int heigth);
void    init_textures_img(t_general *gen, t_image *img, char *path);
int *save_xmp_to_ram(t_general *gen, char *path);
void init_textures(t_general *gen);
void    set_color_pixel(t_image *img, int x, int y, int color);

//textures
void init_textures(t_general *gen);

//map
int check_map(t_general *gen, char **map);
int  check_blanks(char c);
int  blank_space(char c);


//player
void    init_input_hooks(t_general *gen);
int move_player(t_general *gen);
int	validate_move(t_general *gen, double new_x, double new_y);
void init_player_dir(t_player *player);

//ERROR
void error(int code);

//exit
void    clean_exit(t_general *gen, int code);
int quit(t_general *gen);

//free
void    free_tab(void **tab);
int     free_data(t_general *gen);


#endif