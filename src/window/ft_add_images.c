
#include "../includes/images.h"

void    ft_add_images(t_image *image)
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