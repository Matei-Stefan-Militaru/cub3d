/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:29:06 by marvin            #+#    #+#             */
/*   Updated: 2025/07/07 09:29:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

static int  key_press(int key, t_general *gen)
{
    if (key == XK_Escape)
        //fuera de ventana
    if (key == XK_Left)
        gen->pl->rotate -= 1;
    if (key == XK_Right)
        gen->pl->rotate += 1;
    if (key == XK_w)
        gen->pl->move_y = 1;
    if (key == XK_a)
        gen->pl->move_x = -1;
    if (key == XK_s)
        gen->pl->move_y = -1;
    if (key == XK_d)
        gen->pl->move_x = 1;
    return (0);
}

static int  key_release(int key, t_general *gen)
{
    if (key == XK_Escape)
        //fuera de ventana
    if (key == XK_Left && gen->pl->rotate <= 1)
        gen->pl->rotate = 0;
    if (key == XK_Right && gen->pl->rotate >= -1)
        gen->pl->rotate = 0;
    if (key == XK_w && gen->pl->move_y == 1)
        gen->pl->move_y = 1;
    if (key == XK_a && gen->pl->move_x == -1)
        gen->pl->move_x += 1;
    if (key == XK_s && gen->pl->move_y == -1)
        gen->pl->move_y = 0;
    if (key == XK_d && gen->pl->move_x == 1)
        gen->pl->move_x += 1;
    return (0);
}


void    init_input_hooks(t_general *gen)
{
    mlx_hook(gen->win, ClientMessage, NoEventMask, quit, gen);
    mlx_hook(gen->win, KeyPress, KeyPressMask, key_press, gen);
    mlx_hook(gen->win, KeyRelease, KeyReleaseMask, key_release, gen);
}