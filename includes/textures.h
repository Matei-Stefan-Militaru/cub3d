/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:00:41 by marvin            #+#    #+#             */
/*   Updated: 2025/07/02 11:00:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXT_H
#define TEXT_H

#include "../mlx/mlx.h"

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

#endif