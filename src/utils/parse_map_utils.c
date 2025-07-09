/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:34:24 by marvin            #+#    #+#             */
/*   Updated: 2025/07/09 15:42:10 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

int  check_blanks(char c)
{
    //si encuentra algun caracter de ESPACIO VACIO, devolver
    return (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f');
}

int  blank_space(char c)
{
    if (c != ' ' && c != '\t' && c != '\r' && c != '\n' && c != '\v' && c != '\f')
        return (-1);
    return (1);    
}