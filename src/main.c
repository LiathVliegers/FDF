/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:50:05 by livliege          #+#    #+#             */
/*   Updated: 2024/02/27 18:53:19 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib_liath.h"
#include "../inc/fdf.h"




void	ft_load_map(int fd)
{
	int				map_size;
	int				i;
	int				j;
	int				line_size;
	char*			map_line;
	char**			temp_map;
	static int**	map;
	
	map_size = 0;
	i = 0;
	// if (!(map_line = get_next_line(fd))){
	// 	ft_printf("ERROR: empty .fdf map file\n");
	// 	return;
	// }
	// ft_printf("%s", map_line);


	// free(map_line);
	
	while ((map_line = get_next_line(fd)))
	// !!!! Handle it if map is empty
	{
		// ft_printf("%s", map_line);
		// HERE WE NEED TO SPLIT THE LINES INTO A 2D ARRAY INSTEAD OF PRINTING IT
		temp_map = ft_split(map_line, ' ');
		while (temp_map[i] != NULL)
		{
			map[map_size][i] = ft_atoi(temp_map[i]);
			i++;
			line_size++;
		}
		free(map_line);
		ft_free_2d_array(temp_map);
		map_size++;
		i = 0;
	}
	j = 0;
	while (i != map_size)
	{
		while (j != line_size)
		{
			ft_printf("%d", map[i][j]);
			j++;
		}
		i++;
	}

	close(fd);
	return;
}

int		ft_open_fd(char* file_name)
{
	int				fd;
	char*			path;
	
	path = ft_strjoin("maps/", file_name);
	ft_printf("path to map: %s\n", path);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd < 2)
	{
		ft_printf("ERROR: can not open fd file. fd = %d\n", fd);
		//stop program
		return (0);
	}
	ft_printf("fd = %d\n", fd);

	ft_load_map(fd);
	return (0);
}

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		// stop program
		ft_printf("ERROR: No arguments given, please include a .fdf file from the maps directory as argument\n");
		return (0);
	}
	ft_open_fd(argv[1]);
	
	return (0);
}

