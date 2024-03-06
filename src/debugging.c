/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:47:44 by livliege          #+#    #+#             */
/*   Updated: 2024/03/06 19:04:08 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void print_map(t_map_data* map)
{
	int x;
	int y;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_printf("%d ", map->z_values[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}







// int get_map_width(char* file_path)
// {
//     int		fd;
//     int		new_width;

//     fd = open(file_path, O_RDONLY);
//     if (fd < 0)
//         return (ft_putstr_fd("ERROR: invalid fd\n", STDERR_FILENO), -1);
//     new_width = find_max_width(fd);
//     close(fd);
//     return new_width;
// }

// int find_max_width(int fd)
// {
//     int		width;
//     int		new_width;
//     char	*line;
//     char	**split_line;

//     new_width = 0;
//     line = get_next_line(fd);
//     if (line == NULL)
//     {
//         ft_putstr_fd("ERROR: empty map\n", STDERR_FILENO);
//         exit(1);
//     }
//     while (line != NULL)
//     {	
//         split_line = ft_split(line, ' ');
//         width = get_line_width(split_line);
//         free_split_line(split_line);
//         free(line);
//         line = get_next_line(fd);
//         if (new_width < width)
//             new_width = width;
//     }
//     return new_width;
// }

// int get_line_width(char **split_line)
// {
//     int		i;
//     int		width;

//     i = 0;
//     width = 0;
//     while (split_line[i] != NULL)
//     {
//         if (split_line[i][0] != '\n')
//             width++;
//         i++;
//     }
//     return width;
// }

// void free_split_line(char **split_line)
// {
//     int i;

//     i = 0;
//     while (split_line[i] != NULL)
//     {
//         free(split_line[i]);
//         i++;
//     }
//     free(split_line);
// }





