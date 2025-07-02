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

#include "../mlx/mlx.h"

typedef struct s_texture
{
    char    *N; //path a la textura de la pared Norte
    char    *S; //path a la textura de la pared Sud
    char    *W; //path a la textura de la pared Oeste
    char    *E; //path a la textura de la pared Este
    int     *floor; //color de FLOOR
    int     *ceiling; //color de CELING
    int     w_size; //la amplitud de la textura
    int     h_size; //la alargada de la textura

}  t_texture;