/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:36:48 by livliege          #+#    #+#             */
/*   Updated: 2024/06/04 21:02:44 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_exit(char *error_message)
{
	char	*error_mess;

	error_mess = ft_strjoin("ERROR: ", error_message);
	if (error_mess == NULL)
	{
		ft_putstr_fd("Malloc allocation failed\n", STDERR_FILENO);
		exit(1);
	}
	ft_putstr_fd(error_mess, STDERR_FILENO);
	free(error_mess);
	exit(1);
}

void	ft_free_points_matrix(t_point **points, t_map_data *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(points[i]);
		i++;
	}
	free(points);
}

void	ft_free_matrix(char **lines)
{
	int	i;

	i = 0;
	while (lines[i] != NULL)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	ft_free_lines_matrix(char **map_lines, t_map_data *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map_lines[i]);
		i++;
	}
	free(map_lines);
}

void	clear_everything(t_map_data *map)
{
	free(map->title);
	free(map->full_map_buffer);
	ft_free_points_matrix(map->points, map);
	ft_free_lines_matrix(map->map_lines, map);
	free(map);
}
