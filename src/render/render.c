/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 08:34:05 by marvin            #+#    #+#             */
/*   Updated: 2025/07/14 08:34:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

void    set_frame_image_pixel(t_general *gen, t_image *img, int x, int y)
{
    if (gen->text_pixels[y][x] > 0)
        set_color_pixel(img, x, y, gen->text_pixels[y][x]);
    else if (y < gen->win_heigth / 2)
        set_color_pixel(img, x, y, gen->text.hex_ceiling);
    else if (y < gen->win_heigth - 1)
        set_color_pixel(img, x,y,gen->text.hex_floor);
}

static void render_frame(t_general *gen)
{
    t_image img;
    int x;
    int y;

    img.image = NULL;
    init_img(gen, &img, gen->win_width, gen->win_heigth);
    y = 0;
    while (y < gen->win_width)
    {
        x = 0;
        while (x < gen->win_width)
        {
            set_frame_image_pixel(gen, &img, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(gen->mlx, gen->win, img.image, 0, 0);
    mlx_destroy_image(gen->mlx, img.image);
}

static void render_raycast(t_general *gen)
{
    init_textures_pixels(gen);
    init_ray(&gen->ray);
    raycasting(&gen->pl, gen);
    render_frame(gen);

}

void    render_images(t_general *gen)
{
    render_raycast(gen);
}

int     render(t_general *gen)
{
    gen->pl.has_moved += move_player(gen);
    if (gen->pl.has_moved == 0)
        return (0);
    render_images(gen);
    return (0);
}