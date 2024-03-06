/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:35:08 by livliege          #+#    #+#             */
/*   Updated: 2024/03/06 20:55:06 by livliege         ###   ########.fr       */
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
		ft_exit(3);
	line = get_next_line(fd);
	if (line == NULL)
		ft_exit(5);
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


// int get_map_width(char* file_path)
// {
// 	int		i;
// 	int		fd;
// 	int		width;
// 	int		new_width;
// 	char	*line;
// 	char	**split_line;
	
// 	fd = open(file_path, O_RDONLY);
// 	if (fd < 0)
// 		return (ft_putstr_fd("ERROR: invalid fd\n", STDERR_FILENO), -1);
// 	line = get_next_line(fd);
// 	if (line == NULL)
// 	{
// 		ft_putstr_fd("ERROR: empty map\n", STDERR_FILENO);
// 		exit(1);
// 	}
// 	new_width = 0;
// 	while (line != NULL)
// 	{	
// 		split_line = ft_split(line, ' ');
// 		i = 0;
// 		width = 0;
// 		while (split_line[i] != NULL)
// 		{
// 			if (split_line[i][0] != '\n')
// 				width++;
// 			free(split_line[i]);
// 			i++;
// 		}
// 		free(split_line);
// 		free(line);
// 		line = get_next_line(fd);
// 		if (new_width < width)
// 			new_width = width;
// 	}
// 	ft_printf("width = %d\n", new_width);
// 	return (new_width);
// }


int get_width_per_line(char *line)
{
    char	**split_line;
    int		i;
    int		width;

    split_line = ft_split(line, ' ');
    if (split_line == NULL)
		ft_exit(2);
    i = 0;
    width = 0;
    while (split_line[i] != NULL)
    {
        if (split_line[i][0] != '\0')
            width++;
        free(split_line[i]);
        i++;
    }
    free(split_line);
    return (width);
}

int find_max_width(int fd)
{
	int 	width;
    int		new_width;
    char	*line;

    line = get_next_line(fd);
    if (line == NULL)
		ft_exit(5);
    new_width = 0;
    while (line != NULL)
    {
        width = get_width_per_line(line);
        if (new_width < width)
            new_width = width;
        free(line);
        line = get_next_line(fd);
    }
    return (new_width);
}

int get_map_width(char* file_path)
{
    int		fd;
    int		width;

    fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_exit(3);
    width = find_max_width(fd);
	ft_printf("width: %d\n", width);
    return (width);
}
