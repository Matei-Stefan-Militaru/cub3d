/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:10:31 by marvin            #+#    #+#             */
/*   Updated: 2025/07/09 15:35:23 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

/* comprueba los elementos del mapa*/
static int  map_elements(t_general *gen, char **map)
{
    int     i;
    int     j;
    
    i = 0;
    //decimos que player existe
    gen->pl->exist = '0';
    //Recorremos i del mapa
    while (map[i] != NULL)
    {
        j = 0;
        //recorremos i y j del mapa
        while (map[i][j])
        {
            //recorre los chars de una linea para ver si hay espacios en blanco y los salta
            while (check_blanks(map[i][j]))
                j++;
            //si no encuentra los caracteres "1,0,N,S,W o E, printa error"
            if (!ft_strchr("10NSWE", map[i][j]))
                printf("Error\n");
            //si encuentra los caracteres "1, 0, N, S, W,o E y la existalizacion de player, es mas de 1, printa error"
            if (ft_strchr("NSWE", map[i][j]) && gen->pl->exist != '0')
                printf("Error\n");
            //si encuentra los chars "1,0,N,S,W o E" y la existalizacion de player, es solo 1,  assinga existalizacio a la posicion de i y j
            if (ft_strchr("NSWE", map[i][j]) && gen->pl->exist == '0')
                gen->pl->exist = map[i][j];
            j++;
        }
        i++;
    }
    return (0);
}

/*mira la posicion de player no este en blanco*/
static int  map_position(t_general *gen, char **map)
{
    int i;
    int j;
    int k;

    //definimos todas las direcciones, ARRIBA, ABAJO, DER, IZQ.
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    i = gen->pl->pos_x;
    j = gen->pl->pos_y;
    k = 0;
    //mientras K sea menor a las possible dirreciones
    while (k < 4)
    {
        //ni y nj, seran las coordenadas vecina.
        int ni = i + dx[k];
        int nj = j + dy[k];
        // si algo es menor de 0, falla o es mas grande que la mida del mapa
        if (ni < 0 || nj < 0 || map[i] == NULL || nj >= (int)ft_strlen(map[ni]))
            return (-1);
        //si la coord de ni y nj es espacio blanco, devuelve -1
        if (blank_space(map[ni][nj] == -1))
            return (-1);
    }
    return (0);
}

/* la pos del player*/
static int  map_player_pos(t_general *gen, char **map)
{
    int     i;
    int     j;

    //si existe player
    if (gen->pl->exist == '0')
        prinf("ERROR\n");
    i = 0;
    //recorremos i del mapa
    while (map[i])
    {
        j = 0;
        //recorremos las lineas del mapa
        while (map[i][j])
        {
            //si encuentra algun char "NSWE"
            if (ft_strchr("NSWE", map[i][j]))
            {
                //asigna la pos de player
                gen->pl->pos_x = i;
                gen->pl->pos_y = j;
                //asigna los char NSWE, como 0
                map[i][j] = '0';
            }
            j++;
        }
        i++;
    }
    //comprueba si la posicion de player esta bien dentro del mapa
    if (map_position(gen, map) == -1)
        printf("Error\n");
    return (0);
}

/* comprueba si el mapa esta cerrado*/
static int  map_end(t_map *s_map, char **map)
{
    int     i;
    int     j;
    
    i = s_map->end_map;
    while (s_map->file[i][j])
    {
        j = 0;
        while (s_map->file[i][j])
        {
            if (blank_space(map[i][j]))
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

/* comprueba que el mapa este cerrado con 1*/
static int  map_top(char **map)
{
    int i;

    i = 0;
    if (!map || !map[0] || !map[0][i])
        return (-1);
    while (check_blanks(map[0][i]))
        i++;
    while (map[0][i])
    {
        if (map[0][i] != '1')
            return (-1);
        i++;
    }
    return (0);
}

/*comprueba que mapa este cerrado con 1*/
static int  map_bot(char **map, int h)
{
    int j;

    j = 0;
    if (!map || h <= 0 || !map[h - 1] || !map[h - 1][j])
        return (-1);
    while (check_blanks(map[h - 1][j]))
        j++;
    while (map[h - 1][j])
    {
        if (map[h - 1][j] != '1')
            return (-1);
        j++;
    }
    return (0);
}

static int  map_sides(t_map *s_map, char **map)
{
    int     i;
    int     j;

    if (map_top(map) == -1)
        return (-1);
    if (map_bot(map, s_map->height) == -1)
        return (-1);
    i = 1;
    while (i < (s_map->height - 1))
    {
        j = ft_strlen(map[i]) - 1;
        if (j = 0 || map[i][j] != '1' || map[i][j - 1] != '1')
            return (-1);
        i++;
    }
    return (0);
}

int check_map(t_general *gen, char **map)
{
    if (!gen->map)
        error(1);
    if (map_sides(gen->s_map, map) == -1)
        error(1);
    if (gen->s_map->height < 3)
        error(1);
    if (map_elements(gen, map) == -1)
        error(1);
    if (map_player_pos(gen, map) == -1)
        error(1);
    if (map_end(gen->s_map, map) == -1)
        error(1);
    return (0);
}