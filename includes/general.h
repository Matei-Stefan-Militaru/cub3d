/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:22:10 by pmorello          #+#    #+#             */
/*   Updated: 2025/07/09 19:04:39 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
#define GENERAL_H

#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <stdbool.h>
#include <X11/X.h>
#include <X11/Xlib.h>

#define ERROR_MAP "No map found\n"
#define ERROR_ARG "Invalid arguments\n"
#define ERROR_CUB_FORMAT "Map is not a .cub format\n"
#define ERROR_XPM_FORMAT "File is not a .xpm format\n"


typedef struct s_image
{
    void    *image; //puntero en donde esta la IMAGEN guardada en la MEMORIA
    int     *addr; //puntero en donde estan los PIXELES de la IMAGEN en la MEMORIA, sirve para acceder y modificar cada pixel (color, tamaño, etc...)
    int     pixel_bits; //indica cuantos BITS ocupa cada PIXEL, sino el programa puede leer mal los datos
    int     size_line; //indica cuantos BYTES ocupa una linea de la IMAGEN en la MEMORIA
    int     endian; //indica como se guardan los BYTES en la MEMORIA, depende del orden su valor su puede interpretar

} t_image;

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

typedef struct s_texture
{
    char    *N; //path a la textura de la pared Norte
    char    *S; //path a la textura de la pared Sud
    char    *W; //path a la textura de la pared Oeste
    char    *E; //path a la textura de la pared Este
    int     *floor; //color de FLOOR en RGB
    int     *ceiling; //color de CELING en RGB
    unsigned long hex_floor; //color en HEXA, mas rapido de leer
    unsigned long   hex_ceiling; //color en HEXA; mas rapido de leer
    int     w_size; //la amplitud de la textura
    int     h_size; //la alargada de la textura
    //int   size, mezcla de w_szie y h_size
    double  pass; //indica cuantos PIXELS hemos avanzado en la TEXTRUA, cada vez que se dibbuja en la pantalla
    double  pos; //indica en que PIXEL de la TEXTURA esta, cuando se dibuja

    int x; //coordenada dentro de la TEXTURA, para saber que PIXEL acceder
    int y; //coordenada dentro de la TEXTURA, para saber que PIXEL acceder

}  t_texture;

typedef struct s_ray
{
    /* data */
    
} t_ray;


typedef struct s_general
{
    void    *mlx; //puntero a MLX
    void    *win; //puntero para referenciar la ventana
    int     win_heigth; //altura de WIN
    int     win_width; //anchura de WIN
    char    **map; //para guardar el MAPA

    int     **textures; //doble puntero, donde guardar las texturas de las paredes
    int     **text_pixels;

    t_image img; //puntero al STRUCT de IMAGE
    t_texture text; //puntero a la STRUCT de TEXTURE
    t_player pl; //puntero a la STRUCT de PLAYER
    t_map   s_map; //puntero a la STRUCT de MAP
    
} t_general;


//general
void    init_mlx(t_general *gen);
void    init_general(t_general *gen);
void    init_map_params(t_map *map);
void    init_textures_params(t_texture *text);
void    init_player_params(t_player *player);
void    init_images_params(t_image *img);

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
bool check_formats(char **av);


//player
void    init_input_hooks(t_general *gen);
int move_player(t_general *gen);
int	validate_move(t_general *gen, double new_x, double new_y);
void init_player_dir(t_player *player);

//ERROR
int error(char *s, int code);


//exit
void    clean_exit(t_general *gen, int code);
int quit(t_general *gen);

//free
void    free_tab(void **tab);
int     free_data(t_general *gen);


#endif