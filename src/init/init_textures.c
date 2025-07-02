/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:21:52 by marvin            #+#    #+#             */
/*   Updated: 2025/07/02 11:21:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

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