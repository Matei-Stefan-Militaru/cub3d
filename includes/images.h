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
#include "../includes/window.h"

typedef struct s_image
{
    void    *image;
    int     x;
    int     y;

    t_window *win;
    
} t_image;

void    ft_add_images(t_image *image);
void    ft_load_image(t_image *image);

#endif