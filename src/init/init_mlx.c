/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:14:44 by pmorello          #+#    #+#             */
/*   Updated: 2025/07/09 17:16:15 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

void    init_mlx(t_general *gen)
{
    gen->mlx = mlx_init();
    gen->win = mlx_new_window(gen->mlx, gen->win_heigth, gen->win_width, "Cub3D");
}
