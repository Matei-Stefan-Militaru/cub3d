/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:41:34 by pmorello          #+#    #+#             */
/*   Updated: 2025/06/30 22:33:02 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
#define WINDOW_H

#include "../mlx/mlx.h"

typedef struct s_window
{
    void    *mlx;
    void    *win;

} t_window;

void    new_window(t_window *window);

#endif