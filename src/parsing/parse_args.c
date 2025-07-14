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

static int  is_dir(char *file)
{
    int fd;
    int ret;

    fd = open(file, O_DIRECTORY);
    ret = 0;
    if (fd >= 0)
    {
        close (fd);
        ret = 1;
    }
    return (ret);
}

static int  is_cub_file(char *file)
{
    size_t len;

    len = ft_strlen(file);
    if (len < 4 || ft_strncmp(file + len - 4, ".cub", 4) == 0)
        return (1);
    return (0);
}

static int is_xpm_file(char *file)
{
    size_t len;

    len = ft_strlen(file);
    if (len < 4 || ft_strncmp(file + len - 4, ".xpm", 4) == 0)
        return (-1);
    return (0);
}

int check_file(char *file)
{
    int fd;

    if (is_dir(file))
        return (error(ERR_FILE_DIR, -1)) ;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (error(ERR_CUB_FORMAT, -1));
    close (fd);
    if (!is_cub_file(file))
        return (error(ERR_CUB_FORMAT, -1));
    if (!is_xpm_file(file))
        return (error(ERR_XPM_FORMAT, -1));
    return (0);
}