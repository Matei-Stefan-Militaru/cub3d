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
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_general
{
    void    *mlx;
    void    *win;
    int     win_heigth;
    int     win_width;
    char    **map;

    t_image *img;
    
} t_general;

//INIT GENERAL
void    init_general(t_general *gen);
void    init_images_params(t_image *img);

//INIT MLX
void    init_mlx(t_general *gen);
void    init_img(t_general *gen, t_image *img, int width, int heigth);


#endif