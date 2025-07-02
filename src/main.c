
#include "../includes/general.h"

int main(void)
{
    t_general gen;
    
    //if (argc != 2)
    //    printf("Args error\n");
    init_general(&gen);
    //parseo
    init_mlx(&gen);
    mlx_loop(&gen);

    return (0);

}