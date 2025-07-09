/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:12:17 by marvin            #+#    #+#             */
/*   Updated: 2025/07/09 15:48:49 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

void init_player_dir(t_player *player)
{
    if (player->dir == 'S')
    {
        player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
    }
    if (player->dir == 'N')
    {
        player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
    }
    if  (player->dir == 'W')
    {
        player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
    }
    if (player->dir == 'E')
    {
        player->dir_x = 1;
        player->dir_y = 0;
        player->plane_x = 0;
        player->plane_y = 0.66;
    }
}