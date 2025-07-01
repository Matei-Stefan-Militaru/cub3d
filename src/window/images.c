
#include "../includes/images.h"

void    init_images_params(t_image *img)
{
    img->image = NULL;
    img->p_colors = 0;
    img->b_pixel = 0;
    img->size_line = 0;
    img->endian = 0;
}

void    ft_add_images(t_image *img)
{
    int i;
    int j; 

    image->image =  mlx_xpm_file_to_image(image->win->mlx, "../image", &i, &j);
    
}

void    ft_load_image(t_image *image)
{
    int amplada;
    int alcada;

    amplada = image->x;
    alcada = image->y;
    mlx_put_image_to_window(image->win->mlx, image->win->win, image->image, amplada, alcada);
}