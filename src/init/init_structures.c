/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:02:55 by marvin            #+#    #+#             */
/*   Updated: 2025/07/02 10:02:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

/* iniciamos los valores de la struct de TEXTURA */
void    init_text_params(t_texture *text)
{
    text->N = NULL;
    text->S = NULL;
    text->W = NULL;
    text->E = NULL;
    text->floor = 0;
    text->ceiling = 0;
    text->w_size = 64;
    text->h_size = 64;
}

/* iniciamos los valores de la struct de IMAGEN */
void    init_images_params(t_image *img)
{
    img->image = NULL;
    img->addr = NULL;
    img->pixel_bits = 0;
    img->size_line = 0;
    img->endian = 0;
}

/* iniciamos los valores de la struct de PLAYER*/
void    init_player_params(t_player *player)
{
    player->dir = '\0';
    player->exist = '\0';
    player->dir_x = 0.0;
    player->dir_y = 0.0;
    player->pos_x = 0.0;
    player->pos_y = 0.0;
    player->plane_x = 0.0;
    player->plane_y = 0.0;
    player->s_rotate = 0.0;
    player->move_x = 0;
    player->move_y = 0;
    player->rotate = 0;
}

/* iniciamos los valores de la struct de TEXTURAS*/
void    init_textures_params(t_texture *text)
{
    text->N = NULL;
    text->S = NULL;
    text->W = NULL;
    text->E = NULL;
    text->floor = 0;
    text->ceiling = 0;
    text->hex_floor = 0x0;
    text->hex_ceiling = 0x0;
    text->w_size = 64;
    text->h_size = 64;
    text->pass = 0.0;
    text->pos = 0.0;
    text->x = 0;
    text->y = 0;
}

/*iniciamos los valores de de la struct MAP*/
void    init_map_params(t_map *map)
{
    map->fd = 0;
    map->line_count = 0;
    map->path = NULL;
    map->file = NULL;
    map->height = 0;
    map->width = 0;
    map->end_map = 0;
}

/* iniciamos los valores de la struct GENERAL */
void    init_general(t_general *gen)
{
    gen->mlx = NULL;
    gen->win = NULL;
    gen->win_heigth = 400;
    gen->win_width = 600;
    init_player_params(gen->pl);
    init_textures_params(gen->text);
    gen->map = NULL;
    init_map_params(gen->s_map);
    init_images_params(gen->img);
    gen->text_pixels = NULL;
    gen->textures = NULL;
}