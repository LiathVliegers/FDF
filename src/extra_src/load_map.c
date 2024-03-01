/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:27:56 by livliege          #+#    #+#             */
/*   Updated: 2024/03/01 17:35:56 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib_liath.h"
#include "../inc/fdf.h"

#define MAX_ROWS 20
#define MAX_COLS 20

void	ft_load_map(int fd)
{
	char*			line;
	char** 			temp_map;
	int				map[MAX_ROWS][MAX_COLS];
	int				row;	// x
	int 			col;	// y
	int 			x;		// printing purposes only TAKE THIS OUT
	int 			y;		// printing purposes only TAKE THIS OUT
	
	row = 0;
	line = get_next_line(fd);
	if (line == NULL && row == 0)
	{
		ft_printf("ERROR: empty .fdf map file\n");
		return ;
	}
	while (line != NULL)
	{
		// ft_printf("%s", line);
		temp_map = ft_split(line, ' ');
		col = 0;
		while (temp_map[col] != NULL)
		{
			map[row][col] = ft_atoi(temp_map[col]);
			free(temp_map[col]);
			col++;
		}
		free(temp_map);
		free(line);
		row++;
		line = get_next_line(fd);
	}
	
	// print 2d int array TAKE THIS OUT
	x = 0;
	while (x < row)
	{
		y = 0;
		while (y < col)
		{
			ft_printf("%d", map[x][y]);
			y++;
		}
		ft_printf("\n");
		x++;
	}
	return ;
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
	close(fd);
	return (0);
}