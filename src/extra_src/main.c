/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:27:51 by livliege          #+#    #+#             */
/*   Updated: 2024/03/01 16:39:50 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib_liath.h"
#include "../inc/fdf.h"


#define WIDTH 3000
#define HEIGHT 2000

// MY PROGRAM DOES:
// takes a file as argument, opens it and reads the lines, and puts the numbers in an 2d int array.
// opens a window.
// closes the wintow when you press esc.

void ft_hook(void* param)
{
	mlx_t*	mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int main(int argc, char** argv)
{
	mlx_t* 	window;
	// int** 	map;


	if(argc != 2)
	{
		// ft_printf("ERROR: No arguments given, please include a .fdf file from the maps directory as argument\n");
		ft_putstr_fd("ERROR BITCH\n", STDERR_FILENO);
		return (0);
	}

	ft_open_fd(argv[1]);

	// creates a window, with a set width, height, name, and bool for if it's resizable
	window = mlx_init(WIDTH, HEIGHT, "LIATH'S FDF!", false);

	mlx_loop_hook(window, ft_hook, window);
	mlx_loop(window);
	mlx_terminate(window);

	return (0);
}

