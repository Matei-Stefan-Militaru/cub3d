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
    int     *addr; //punter a la memoria dels pixels de la imatge, per poder modificar el valor dels pixels
    int     pixel_bits; //quants bits per pixels
    int     size_line; //mida en bytes de una linea de la imatge
    int     endian; //indica com s'emmagatzmen els bytes dels colors

} t_image;

#endif