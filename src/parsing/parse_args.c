/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:34:45 by pmorello          #+#    #+#             */
/*   Updated: 2025/07/09 18:49:17 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

static int  is_cub_file(char *file)
{
    size_t len;

    len = ft_strlen(file);
    if (len < 4 || ft_strncmp(file + len - 4, ".cub", 4) != 0)
        return (-1);
    return (0);
}

static int is_xpm_file(char *file)
{
    size_t len;

    len = ft_strlen(file);
    if (len < 4 || ft_strcmp(file + len - 4, ".xpm", 4) != 0)
        return (-1);
    return (0);
}

int check_args(char **av)
{
    while (av[1])
    {
        if (is_cub_file(av[1]) != 0)
            return (error(ERROR_CUB_FORMAT, -1));
        if (!is_xpm_file(av[1]))
            return (error(ERROR_XPM_FORMAT, -1));
    }
    return (0);
}