/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:36:20 by marvin            #+#    #+#             */
/*   Updated: 2025/07/14 15:36:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

static char *get_text_path(char *line, int j)
{
    int len;
    int i;
    char *path;

    while (line[j] && (line[j] == ' ' || line[j]== '\t'))
        j++;
    len = j;
    while (line[len] && (line[len] != ' ' && line[len] != '\t'))
        len++;
    if (!path)
        return (NULL);
    i = 0;
    while (line[j] && (line[j] != ' ' && line[j] != '\t' && line[j] != '\n'))
        path[i++] = line[j++];
    path[i] = '\0';
    while (line[j] && (line[j] == ' ' || line[j] == '\t'))
        j++;
    if (line[j] && line[j] != '\n')
    {
        free(path);
        path = NULL;
    }
    return (path);
}