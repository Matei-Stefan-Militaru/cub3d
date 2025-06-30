
#include "../includes/window.h"
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    t_window *w;
    
    w = (t_window *)malloc(sizeof(t_window));
    new_window(w);
    mlx_loop(w->mlx);

    return (0);

}