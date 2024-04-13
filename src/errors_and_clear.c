/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liath <liath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:36:48 by livliege          #+#    #+#             */
/*   Updated: 2024/04/13 23:03:11 by liath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"





// 1: ERROR: Incorrect number of arguments
// 2: ERROR: Memory allocation failed
// 3: ERROR: Reading the file failed
// 4: ERROR: Invalid map file
// 5: ERROR: Empty map
// 6: ERROR: Lines in file are not consistent


void	ft_exit(int error_code)
{
	char* error_message;
	
	if (error_code == 1)
		error_message = "ERROR: Incorrect number of arguments\nPlease include the path to a .fdf map file as argument\n";
	else if (error_code == 2)
		error_message = "ERROR: Memory allocation failed\n";
	else if (error_code == 3)
		error_message = "ERROR: Reading the file failed\n";
	else if (error_code == 4)
		error_message = "ERROR: Invalid map file\n";
	else if (error_code == 5)
		error_message = "ERROR: Empty map\n";
	else if (error_code == 6)
		error_message = "ERROR: Lines in file are not consistent\n";
	else if (error_code == 7)
		error_message = "ERROR: Loading the menu failed\n";
	else if (error_code == 8)
		error_message = "ERROR: Loading the image (menu) failed\n";
	else if (error_code == 9)
		error_message = "ERROR: Loading the window (menu) failed\n";
	else
		error_message = "ERROR: Unknown error\n";
	ft_putstr_fd(error_message, STDERR_FILENO);
	exit(1);
}

void	ft_free_points_matrix(t_point **points, t_map_data *map)
{
	int i;

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
	int i;

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
	int i;

	i = 0;
	while (i < map->height)
	{
		free(map_lines[i]);
		i++;
	}
	free(map_lines);
}

void clear_everything(t_map_data *map)
{
	free(map->title);
	free(map->full_map_buffer);
	ft_free_points_matrix(map->points, map);
	ft_free_lines_matrix(map->map_lines, map);
	free(map);
}
