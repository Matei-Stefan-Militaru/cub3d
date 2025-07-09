/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:07:19 by marvin            #+#    #+#             */
/*   Updated: 2025/07/09 16:58:31 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

static int  move_forward(t_general *gen)
{
    double  new_x;
    double  new_y;
    int move;

    new_x = gen->pl.pos_x + gen->pl.dir_x * 0.0125;
    new_y = gen->pl.pos_y + gen->pl.dir_y * 0.0125;
    move = validate_move(gen, new_x, new_y);
    return (move);
}

static int  move_backward(t_general *gen)
{
    double  new_x;
    double  new_y;
    int move;

    new_x = gen->pl.pos_x - gen->pl.dir_x * 0.0125;
    new_y = gen->pl.pos_y - gen->pl.dir_y * 0.0125;
    move = validate_move(gen, new_x, new_y);
    return (move);
}

static int  move_left(t_general *gen)
{
    double  new_x;
    double  new_y;
    int move;

    new_x = gen->pl.pos_x + gen->pl.dir_x * 0.0125;
    new_y = gen->pl.pos_y - gen->pl.dir_y * 0.0125;
    move = validate_move(gen, new_x, new_y);
    return (move);
}

static int  move_rigth(t_general *gen)
{
    double  new_x;
    double  new_y;
    int move;

    new_x = gen->pl.pos_x - gen->pl.dir_x * 0.0125;
    new_y = gen->pl.pos_y + gen->pl.dir_y * 0.0125;
    move = validate_move(gen, new_x, new_y);
    return (move);
}

int move_player(t_general *gen)
{
    int moved;

    moved = 0;
    if (gen->pl.move_y == 1)
        moved += move_forward(gen);
    if (gen->pl.move_y == -1)
        moved += move_backward(gen);
    if (gen->pl.move_x == -1)
        moved += move_left(gen);
    if (gen->pl.move_x == 1)
        moved += move_rigth(gen);
    if (gen->pl.rotate != 0)
        moved = gen->pl.rotate;
    return (moved);
}