
#include "../includes/general.h"

static int  parse(t_general *gen, char **av)
{
    if (check_formats(av) == false)
        error(ERR_CUB_FORMAT, -1);   
    else if (check_map(gen, av) == -1)
        error(ERR_MAP, -1);
         
    return (0);
}

int main(int argc, char **av)
{
    t_general gen;

    if (argc != 2)
    {
        error(ERR_ARG, -1);
        return (-1);
    }
    init_general(&gen);
    if (parse(&gen, av) != 0)
        exit (EXIT_FAILURE);
    init_mlx(&gen);
    //init_images()
    //render_images()
    init_input_hooks(&gen);
    mlx_loop(&gen);
    return (0);

}