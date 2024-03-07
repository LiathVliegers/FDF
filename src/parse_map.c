/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:47:42 by livliege          #+#    #+#             */
/*   Updated: 2024/03/07 16:22:49 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"



void parse_map_file(char* file_path, t_map_data* map)
{
	int		i;
	int		fd;
	char	*line;
	
	validate_map_name(file_path, map);
	map->height = get_map_height(file_path);
	map->width = get_map_width(file_path);
	allocate_memory_map(map);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_exit(3);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL && i < map->height)
	{
		fill_map(map->points[i], line, map);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	
	// // TODO: CLOSE ALL FD'S IN A BETTER WAY, like this?:
	// while (fd > 1)
	// {
	// 	close(fd);
	// 	fd--;
	// }
	
	close(3);
	close(4);
	close(fd);
}

