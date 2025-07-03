/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:34:24 by marvin            #+#    #+#             */
/*   Updated: 2025/07/03 10:34:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

static int  check_blanks(char c)
{
    //si encuentra algun caracter de ESPACIO VACIO, devolver
    return (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f');
}

static int  check_blanks_end(char c)
{
       return ( c != ' ' || c != '\t' || c != '\r' || c != '\n'|| c != '\v' || c != '\f');
}