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

typedef struct s_image
{
    void    *image; //puntero en donde esta la IMAGEN guardada en la MEMORIA
    int     *addr; //puntero en donde estan los PIXELES de la IMAGEN en la MEMORIA, sirve para acceder y modificar cada pixel (color, tamaño, etc...)
    int     pixel_bits; //indica cuantos BITS ocupa cada PIXEL, sino el programa puede leer mal los datos
    int     size_line; //indica cuantos BYTES ocupa una linea de la IMAGEN en la MEMORIA
    int     endian; //indica como se guardan los BYTES en la MEMORIA, depende del orden su valor su puede interpretar

} t_image;

#endif