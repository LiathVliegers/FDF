/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:36:48 by livliege          #+#    #+#             */
/*   Updated: 2024/06/03 19:08:12 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_exit(int error_code)
{
	char	*error_message;

	if (error_code == 1)
		error_message = "ERROR: Incorrect number of arguments\n \
		Please include the path to a valid .fdf map file as argument\n";
	else if (error_code == 2)
		error_message = "ERROR: Memory allocation failed\n";
	else if (error_code == 3)
		error_message = "ERROR: Reading the file failed\n";
	else if (error_code == 4)
		error_message = "ERROR: Invalid map\n";
	else if (error_code == 5)
		error_message = "ERROR: Empty map\n";
	else if (error_code == 6)
		error_message = "ERROR: Inconsistent lines in file\n";
	else if (error_code == 7)
		error_message = "ERROR: Loading the menu failed\n";
	else
		error_message = "ERROR: Unknown error\n";
	ft_putstr_fd(error_message, STDERR_FILENO);
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
