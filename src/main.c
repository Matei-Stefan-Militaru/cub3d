
#include "../includes/general.h"

int main(void)
{
    t_general gen;
    

    init_general(&gen);
    //parse
    init_mlx(&gen);
     //render_images
    init_input_hooks(&gen);
    mlx_loop(&gen);
    return (0);

}