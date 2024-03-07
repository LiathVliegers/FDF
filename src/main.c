/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:46:53 by livliege          #+#    #+#             */
/*   Updated: 2024/03/07 20:42:29 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_hook(void* param)
{
	mlx_t*	mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	create_window(t_map_data* map)
{
	mlx_t* 	window;

	window = mlx_init(WIDTH, HEIGHT, map->title, true);

	mlx_loop_hook(window, ft_hook, window);
	mlx_loop(window);
	mlx_terminate(window);
}

int	main (int argc, char** argv)
{
	t_map_data* map;

	if (argc != 2)
		ft_exit(1);	// 1: ERROR: Incorrect number of arguments

	map = (t_map_data*)malloc(sizeof(t_map_data));
	if (map == NULL)
		ft_exit(2);	// 2: ERROR: Memory allocation failed

	parse_map_file(argv[1], map);
	
	print_map(map);
	
	// create_window(map);
	
	free_map(map);
}


