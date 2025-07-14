/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:21:46 by marvin            #+#    #+#             */
/*   Updated: 2025/07/14 15:21:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/general.h"

static int has_non_digit(const char *str)
{
	int	i;

    i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

// Converteix un array de cadenes a RGB; retorna NULL si hi ha error
static int	*convert_rgb(char **tokens)
{
	int	*rgb = malloc(sizeof(int) * 3);
	int	i;

	if (!rgb)
		return (NULL);
	for (i = 0; i < 3; i++)
	{
		rgb[i] = ft_atoi(tokens[i]);
		if (rgb[i] == -1 || has_non_digit(tokens[i]))
		{
			free_tab((void **)tokens);
			free(rgb);
			return (NULL);
		}
	}
	free_tab((void **)tokens);
	return (rgb);
}

// Analitza una línia i retorna un array RGB, o NULL si falla
static int	*parse_rgb(const char *line)
{
	char	**tokens = ft_split(line, ',');
	int		count = 0;

	while (tokens && tokens[count])
		count++;
	if (!tokens || count != 3)
	{
		free_tab((void **)tokens);
		return (NULL);
	}
	return (convert_rgb(tokens));
}

// Omple textures amb colors de sostre i terra, segons la línia del mapa
int	fill_color_textures(t_general *gen, t_texture *text, char *line, int j)
{
	if (line[j + 1] && ft_isprint(line[j + 1]))
		return (error(ERR_FLOOR_CEILING, -1));

	if (line[j] == 'C' && !text->ceiling)
	{
		text->ceiling = parse_rgb(line + j + 1);
		if (!text->ceiling)
			return (error(ERR_CEILING, -1));
	}
	else if (line[j] == 'F' && !text->floor)
	{
		text->floor = parse_rgb(line + j + 1);
		if (!text->floor)
			return (error(ERR_FLOOR, -1));
	}
	else
		return (error(ERR_FLOOR_CEILING, -1));
	return (0);
}