/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:02:55 by marvin            #+#    #+#             */
/*   Updated: 2025/07/02 10:02:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

void    init_images_params(t_image *img)
{
    img->image = NULL;
    img->addr = NULL;
    img->pixel_bits = 0;
    img->size_line = 0;
    img->endian = 0;
}

void    init_general(t_general *gen)
{
    gen->mlx = NULL;
    gen->win = NULL;
    gen->win_heigth = 400;
    gen->win_width = 600;
    gen->map = NULL;
    init_images_params(&gen->img);
}