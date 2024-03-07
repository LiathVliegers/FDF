/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:35:08 by livliege          #+#    #+#             */
/*   Updated: 2024/03/07 21:26:03 by livliege         ###   ########.fr       */
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
		ft_exit(3);	// 3: ERROR: Invalid fd
	line = get_next_line(fd);
	if (line == NULL)
		ft_exit(5);	// 5: ERROR: Empty map
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	ft_printf("height: %d\n", height);		// TAKE THIS OUT!!!!!!!!!!!!!!
	close(fd);
	return (height);
}

/* int get_width_per_line(char *line)
{
    char	**split_line;
    int		i;
    int		width;

    split_line = ft_split(line, ' ');
    if (split_line == NULL)
		ft_exit(2);		// 2: ERROR: Memory allocation failed
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
} */

int get_width_per_line(char *line)
{
    int		i;
    int		width;

	i = 0;
	width = 1;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == ' ')
			width++;
		i++;
	}
    return (width);
}

int validate_width(int fd)
{
	int 	old_width;
    int		new_width;
    char	*line;

    line = get_next_line(fd);
    if (line == NULL)
		ft_exit(5);		// 5: ERROR: Empty map
    old_width = get_width_per_line(line);
    while (line != NULL)
    {
        new_width = get_width_per_line(line);
        if (new_width != old_width)
            ft_exit(6);	// 6: ERROR: Lines in file are not consistent
        free(line);
        line = get_next_line(fd);
    }
    return (old_width);
}


int get_map_width(char* file_path)
{
    int		fd;
    int		width;

    fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_exit(3);		// 3: ERROR: Invalid fd
    width = validate_width(fd);
	ft_printf("width: %d\n", width);	// TAKE THIS OUT!!!!!!!!!!!!
	close(fd);
    return (width);
}

