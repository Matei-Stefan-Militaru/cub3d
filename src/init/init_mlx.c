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


/* creamos una imagen vacia que podemos dibujar despues pixel a pixel*/

void    init_img(t_general *gen, t_image *img, int width, int heigth)
{
    //iniciamos valores
    init_images_params(img);
    //se crea una imagen en negro o vacio
    img->image = mlx_new_image(gen->mlx, width, heigth); 
    if (img->image == NULL)
        printf("Error IMG\n");
    //accedemos a los datos de los pixeles para poder modificar
    img->addr = (int *)mlx_get_data_addr(img->image, &img->pixel_bits, 
        &img->size_line, &img->endian); 
    
}

/* cogemos una imagen desde PATH y la pasamos de XMP a imagen*/

void    init_textures_img(t_general *gen, t_image *img, char *path)
{
    //iniciamos valores
    init_images_params(img);
    //cargamos la imagen XMP desde PATH
    img->image = mlx_xpm_file_to_image(gen->mlx, path, &gen->text->size, &gen->text->size); 
    if (img->image == NULL)
        printf("Error en textura\n");
    //accedemos a los datos de los pixeles de esta imagen
    img->addr = (int *)mlx_get_data_addr(img->image, &img->pixel_bits,
        &img->size_line, &img->endian);
    
}

/* iniciamos la MLX (ventana) */

void    init_mlx(t_general *gen)
{
    //iniciamos MLX
    gen->mlx = mlx_init(); 
    if (!gen->mlx)
        printf("Error\n");
    //iniciamos ventana
    gen->win = mlx_new_window(gen->mlx, gen->win_width, gen->win_heigth, "Cub3D"); 
    if (!gen->win)
        printf("Error en win\n");
}