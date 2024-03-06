/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:47:42 by livliege          #+#    #+#             */
/*   Updated: 2024/03/06 19:09:26 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int get_map_height(char* file_path)
{
	int		fd;
	int		height;
	char	*line;
	
	height = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("ERROR: invalid fd\n", STDERR_FILENO), -1);
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_putstr_fd("ERROR: empty map\n", STDERR_FILENO);
		exit(1);
	}
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	ft_printf("height: %d\n", height);
	return (height);
}


int get_map_width(char* file_path)
{
	int		i;
	int		fd;
	int		width;
	int		new_width;
	char	*line;
	char	**split_line;
	
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("ERROR: invalid fd\n", STDERR_FILENO), -1);
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_putstr_fd("ERROR: empty map\n", STDERR_FILENO);
		exit(1);
	}
	new_width = 0;
	while (line != NULL)
	{	
		split_line = ft_split(line, ' ');
		i = 0;
		width = 0;
		while (split_line[i] != NULL)
		{
			if (split_line[i][0] != '\n')
				width++;
			free(split_line[i]);
			i++;
		}
		free(split_line);
		free(line);
		line = get_next_line(fd);
		if (new_width < width)
			new_width = width;
	}
	ft_printf("width = %d\n", new_width);
	return (new_width);
	// CHECK IF EVERY LINE IS THE SAME, IF NOT, UPDATE THE NEW WIDTH!
}










void fill_map(int* z_value, char* line, t_map_data* map)
{
	char	**split_line;
	int 	i;
	int 	j;

	split_line = ft_split(line, ' ');
	if (split_line == NULL)
		return (ft_putstr_fd("ERROR: Memory allocation failed\n", STDERR_FILENO));
	i = 0;
	j = 0;
	while (split_line[j] != NULL)
	{
		if (split_line[j][0] != '\n')
			z_value[i] = ft_atoi(split_line[j]);
		free(split_line[j]);
		i++;
		j++;
	}
	while (split_line[j] == NULL && i < map->width)
	{
		z_value[i] = 0;
		i++;
	}
	free(split_line);
}

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
		return (ft_putstr_fd("ERROR: invalid fd\n", STDERR_FILENO));
	i = 0;
	line = get_next_line(fd);
	while (line != NULL && i < map->height)
	{
		fill_map(map->z_values[i], line, map);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	// TODO: CLOSE ALL FD'S IN A BETTER WAY
	close(3);
	close(4);
	close(fd);
}



void	validate_map_name(char *path, t_map_data* map)
{
    int		i;

	i = ft_strlen(path) - 1;
	// TODO: GET MILAN TO BREAK MY MAP VALIDATION (because vincent couldn't muhahaha)
	if ((i + 1) < 4 || (!((path[i] == 'f') && (path[i - 1] == 'd') && (path[i - 2] == 'f') && (path[i - 3] == '.'))))
	{
		ft_putstr_fd("ERROR: invalid map file \n", STDERR_FILENO);
		exit(1);
	}	
    while (i >= 0 && path[i] != '/')
        i--;
    i++;
	map->title = ft_strjoin("LIATH'S FDF!	map: ", path + i);
}















