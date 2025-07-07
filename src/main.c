
#include "../includes/general.h"

int main(void)
{
    t_general gen;
    
    //if (argc != 2)
    //    printf("Args error\n");
    init_general(&gen);
    if (parse(&gen) != 0)
        return (1);
    init_mlx(&gen);
    initx_texture(&gen);
    //render_images
    init_intput_hooks(&gen);
    mlx_loop(&gen);
    return (0);

}