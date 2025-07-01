
#include "../includes/window.h"
#include <stdlib.h>
#include <unistd.h>

void    init_win_params(t_window *win)
{
   //definir els parametres, basicament posar 0 la llista 
}


void new_window(t_window *window)
{
    window->mlx = mlx_init();
    if (!window->mlx)
    {
        write(2, "Error: mlx_init failed\n", 24);
        exit(1);
    }

    window->win = mlx_new_window(window->mlx, 800, 600, "cub3d");
    if (!window->win)
    {
        write(2, "Error: mlx_new_window failed\n", 30);
        exit(1);
    }

}
