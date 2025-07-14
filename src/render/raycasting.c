/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:54:31 by marvin            #+#    #+#             */
/*   Updated: 2025/07/14 09:54:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

static void init_raycasting(int x, t_ray *ray, t_player *pl)
{
    init_ray_params(ray);
    ray->camera_x = 2 * x / (double)600 - 1;
    ray->dir_x = pl->dir_x + pl->plane_x * ray->camera_x;
    ray->dir_y = pl->dir_y + pl->plane_y * ray->camera_x;
    ray->map_x = (int)pl->pos_x;
    ray->map_y = (int)pl->pos_y;
    ray->deltadist_x = fabs(1 / ray->dir_x);
    ray->deltadist_y = fabs(1 / ray->dir_y);
}

static void set_dda(t_ray *ray, t_player *pl)
{
    if (ray->dir_x < 0)
    {
        ray->step_x = -1;
        ray->sidedist_x = (pl->pos_x - ray->map_x) * ray->deltadist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->sidedist_x = (ray->map_x + 1.0 - pl->pos_x) * ray->deltadist_x;
    }
    if (ray->dir_y < 0)
    {
        ray->step_y = -1;
        ray->sidedist_y = (pl->pos_y - ray->map_y) * ray->deltadist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->sidedist_y = (ray->map_y + 1.0 - pl->pos_y) * ray->deltadist_y;
    }
}

static int	is_out_of_bounds(t_general *gen, t_ray *ray)
{
	return (ray->map_y < 0 || ray->map_x < 0
		|| ray->map_y >= gen->s_map.height
		|| ray->map_x >= gen->s_map.width);
}

static int	is_wall(t_general *gen, t_ray *ray)
{
	return gen->map[ray->map_y][ray->map_x] > '0';
}

static void	perform_dda(t_general *gen, t_ray *ray)
{
	while (1)
	{
		// Pas del raig
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}

		if (is_out_of_bounds(gen, ray) || is_wall(gen, ray))
			break;
	}
}

static void	calculate_line_height(t_ray *ray, t_general *gen, t_player *player)
{
	int half_height;

    half_height = 0;
    // Distància real fins al mur
	if (ray->side == 0)
        ray->wall_dist = ray->sidedist_x - ray->deltadist_x;
    else
        ray->sidedist_y - ray->deltadist_y;
	// Alçada de la línia projectada
	ray->line_height = (int)(gen->win_heigth / ray->wall_dist);
	// Determina on comença i acaba la línia a la pantalla
	half_height = gen->win_heigth / 2;
	ray->draw_start = half_height - ray->line_height / 2;
	ray->draw_end   = half_height + ray->line_height / 2;

	// Corregeix els valors si cal
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= gen->win_heigth)
		ray->draw_end = gen->win_heigth - 1;

	// Coordenada exacta d'impacte (wall_x)
	if (ray->side == 0)
		ray->wall_dist = player->pos_y + ray->wall_dist * ray->dir_y;
    else
        ray->wall_dist = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

int raycasting(t_general *gen, t_player *pl)
{
    t_ray   ray;
    int x;

    x = 0;
    ray = gen->ray;
    while (x < gen->win_width)
    {
        init_raycasting(x, &ray, pl);
        set_dda(&ray, pl);
        perform_dda(gen, &ray);
        calculate_line_height(&ray, gen, pl);
        update_texture_pixels(gen, &gen->text, &ray, x);
        x++;
    }
    return (0);    
}