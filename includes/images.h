/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:30:16 by pmorello          #+#    #+#             */
/*   Updated: 2025/06/30 22:09:06 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_H
#define IMAGES_H

#include "../mlx/mlx.h"
#include "../includes/window.h"

typedef struct s_image
{
    void    *image; //puntero para refernciar la imagen
    int     *p_colors; //(pixel_colors) puntero para escribir los colores de los pixeles
    int     b_pixel; // (bits_pixel) para saber como construir un pixel
    int     size_line; //sirve para navegar por el buffer de pixel_colors
    int     endian; // define el orden de cada byte para cada pixel
    
} t_image;

void    ft_add_images(t_image *image);
void    ft_load_image(t_image *image);

#endif