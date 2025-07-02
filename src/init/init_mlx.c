/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:12:20 by marvin            #+#    #+#             */
/*   Updated: 2025/07/02 10:12:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"


void    init_img(t_general *gen, t_image *img, int width, int heigth)
{
    init_images_params(img);
    img->image = mlx_new_image(gen->mlx, width, heigth);
    if (img->image == NULL)
        printf("Error IMG\n");
    img->addr = (int *)mlx_get_data_addr(img->image, &img->pixel_bits, 
        &img->size_line, &img->endian);
}

void    init_mlx(t_general *gen)
{
    gen->mlx = mlx_init();
    if (!gen->mlx)
        printf("Error\n");
    gen->win = mlx_new_window(gen->mlx, gen->win_width, gen->win_heigth, "Cub3D");
    if (!gen->win)
        printf("Error en win\n");
}