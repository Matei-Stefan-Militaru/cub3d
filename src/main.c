
#include "../includes/general.h"

int main(void)
{
    t_window *w;
    
    w = (t_window *)malloc(sizeof(t_window));
    new_window(w);
    //ft_add_images(w->img);
    mlx_loop(w->mlx);

    return (0);

}