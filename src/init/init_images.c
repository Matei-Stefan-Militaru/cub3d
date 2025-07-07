/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:07:01 by marvin            #+#    #+#             */
/*   Updated: 2025/07/07 09:07:01 by marvin           ###   ########.fr       */
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
    img->image = mlx_xpm_file_to_image(gen->mlx, path, &gen->text->h_size, &gen->text->w_size); 
    if (img->image == NULL)
        printf("Error en textura\n");
    //accedemos a los datos de los pixeles de esta imagen
    img->addr = (int *)mlx_get_data_addr(img->image, &img->pixel_bits,
        &img->size_line, &img->endian);
    
}

/* iniciamos las texturas de las paredes*/
void init_textures(t_general *gen)
{
    int i;

    i = 0;
    //creamos con malloc 5 espacios t_textures
    gen->text = malloc(5 * sizeof(*gen->text));
    if (!gen->text)
        printf("Error\n"); 
    //iniciamos los espacios a 0
    ft_memset(gen->text, 0, 5 * sizeof(*gen->text));
    //asignamos cada array de int **textures de general, su imagen XMP
    gen->textures[0] = mlx_xpm_to_image(gen, gen->text->N, gen->text->w_size, gen->text->h_size);
    gen->textures[1] = mlx_xpm_to_image(gen, gen->text->S, gen->text->w_size, gen->text->h_size);
    gen->textures[2] = mlx_xpm_to_image(gen, gen->text->W, gen->text->w_size, gen->text->h_size);
    gen->textures[3] = mlx_xpm_to_image(gen, gen->text->E, gen->text->w_size, gen->text->h_size);
}