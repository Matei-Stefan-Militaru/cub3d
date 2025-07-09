/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:13:16 by marvin            #+#    #+#             */
/*   Updated: 2025/07/09 16:59:33 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

static bool	is_valid_pos_wall_collision(t_general *gen, double x, double y)
{
	int i;
    int j;

    i = (int) x;
    j = (int) y;
    if (gen->map[j][i] == '0')
		return (true);
	return (false);
}

static bool	is_valid_pos_in_map(t_general *gen, double x, double y)
{
	if (x < 0.25 || x >= gen->s_map.width - 1.25)
		return (false);
	if (y < 0.25 || y >= gen->s_map.height -0.25)
		return (false);
	return (true);
}

static bool	is_valid_pos(t_general *gen, double x, double y)
{
	if (is_valid_pos_in_map(gen, x, y))
		return (true);
	if (is_valid_pos_wall_collision(gen, x, y))
		return (true);
	return (false);
}

int	validate_move(t_general *gen, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(gen, new_x, gen->pl.pos_y))
	{
		gen->pl.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_pos(gen, gen->pl.pos_x, new_y))
	{
		gen->pl.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}