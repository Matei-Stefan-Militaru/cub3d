/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:34:45 by pmorello          #+#    #+#             */
/*   Updated: 2025/07/09 19:04:27 by pmorello         ###   ########.fr       */
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
    if (len < 4 || ft_strncmp(file + len - 4, ".xpm", 4) != 0)
        return (-1);
    return (0);
}

bool check_formats(char **av)
{
    while (av[1])
    {
        if (is_cub_file(av[1]) != 0)
            return (false);
        if (is_xpm_file(av[1]) != 0)
            return (true);
    }
    return (0);
}