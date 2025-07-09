
#include "../includes/general.h"

static int  parse(t_general *gen)
{
    //parse
}


int main(void)
{
    t_general gen;
    

    init_general(gen);
    if (parse(&gen) == 1)
        return (1);
    init_mlx(gen);
    init_texture(gen);
    //render_images
    init_intput_hooks(&gen);
    mlx_loop(&gen);
    return (0);

}