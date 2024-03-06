/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:46:53 by livliege          #+#    #+#             */
/*   Updated: 2024/03/06 19:10:18 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
PLAN van aanpak:

1.	open file with the correct path 
2.	parse the map:
	- get height
	- get width
	- malloc that shit and free when we're done
	- atoi the string to ints and put in int** array (or struct array)
	- make array of structs with x, y, z values of the points

	how?:
	get next line = first line
	we now have the y = 0, we can use ft_split to get the amount of x elements. 
	We check the string at the x locations and use atoi to get the int value (z)
	every time we check one index lower, we increment x
	for every index in an array of structs of type Point we document the y, the x, and the z
	then we get out of the function and we parsed the first line succesfully
	we then increment y, and keep doing this untill get_next_line returns NULL
	now we have an array of structs Point that stores all values of x, y and z.

	when we draw, we check the value of x and y for the position, and the value of z for the height
	
	
3.	- open a window with the name of the file
4.	- create an image with the grid and display this in the window
5.	- 
6.	
7.	
8.	
9.	
10.	
11.	
12.	
13.	
	not ideal to read the fd more than once
*/

#include "../inc/fdf.h"

void	ft_hook(void* param)
{
	mlx_t*	mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	main (int argc, char** argv)
{
	t_map_data* map;
	// mlx_t* 	window;

	if (argc != 2)
		return (ft_putstr_fd("ERROR: incorrect number of arguments\n", STDERR_FILENO), 1);
	map = (t_map_data*)malloc(sizeof(t_map_data));
	if (map == NULL)
		return (ft_putstr_fd("ERROR: Memory allocation failed\n", STDERR_FILENO), 1);
	
	parse_map_file(argv[1], map);
	

	print_map(map);
	// ft_printf("%s\n", map->title);
	
	// window = mlx_init(WIDTH, HEIGHT, map->title, false);

	// mlx_loop_hook(window, ft_hook, window);
	// mlx_loop(window);
	// mlx_terminate(window);

	free_map(map);
}

