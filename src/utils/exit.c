/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:56:08 by marvin            #+#    #+#             */
/*   Updated: 2025/07/07 09:56:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

void    clean_exit(t_general *gen, int code)
{
    if (!gen)
        exit(code);
    if (gen->win && gen->mlx)
        mlx_destroy_window(gen->mlx, gen->win);
    if (gen->mlx)
    {
        mlx_destroy_display(gen->mlx);
        mlx_loop_end(gen->mlx);
        free(gen->mlx);
    }
    free(gen);
    exit(code);
}

int quit(t_general *gen)
{
    clean_exit(gen, 0);
    return (0);
}