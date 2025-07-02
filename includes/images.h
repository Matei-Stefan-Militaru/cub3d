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
    void    *image; //puntero para refernciar la imagen
    int     *addr; //puntero a la memoria de los pixels, para modificar su valor
    int     pixel_bits; //num de bits por pixel
    int     size_line; //mida de la linea de una imagen
    int     endian; //indica como se guardan los bytes, para dp poder modificar

} t_image;

#endif