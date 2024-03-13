/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:46:53 by livliege          #+#    #+#             */
/*   Updated: 2024/03/13 17:56:35 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#define MAX(a, b)(a > b ? a : b)
#define MOD(a)(a < 0 ? -a : a)
#define FT_PI 3.14159265358979323846
#define FT_TWO_PI 3.14159265358979323846 * 2



int32_t ft_pixel_colour(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}	

void bresenham_line(float x, float y, float x1, float y1, t_map_data *map)
{
	float x_step;
	float y_step;
	int max;
	uint32_t colour;

	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	
	colour = 0xFFFFFF;
	while((int)(x - x1) || (int)(y - y1))
	{
		mlx_put_pixel(map->image, x, y, colour);
		x += x_step;
		y += y_step;
	}
}


void	ft_hook(void* param)
{
	mlx_t*	mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}








void	create_window(t_map_data* map)
{
	map->window = mlx_init(WIDTH, HEIGHT, map->title, true);
	map->image = mlx_new_image(map->window, WIDTH, HEIGHT);
	mlx_image_to_window(map->window, map->image, 0, 0);


	// make_grid(map);
	rose_curve(map);
	

	mlx_loop_hook(map->window, ft_hook, map->window);
	mlx_loop(map->window);
	mlx_terminate(map->window);
}

int	main (int argc, char** argv)
{
	t_map_data	*map;

	if (argc != 2)
		ft_exit(1);	// 1: ERROR: Incorrect number of arguments

	map = (t_map_data*)malloc(sizeof(t_map_data));
	if (map == NULL)
		ft_exit(2);	// 2: ERROR: Memory allocation failed

	parse_map_file(argv[1], map);
	
	print_map(map);
	
	create_window(map);
	
	free_map(map);
}






// void rose_curve_cgpt(t_map_data *map) {
//     int colour = 0xFFFFFF;
//     int n = 5;
//     int d = 8;
//     double k = (double)n / d; // Convert to double for accurate division
//     double angle;
//     double radius;
//     int x;
//     int y;
//     int i = 0;

//     while (i < 36100) { // Adjusted loop condition
//         angle = (i / 10.0) * FT_PI / 180.0; // Convert to radians and use double
//         radius = 300 * cos(k * angle);
//         x = (int)(radius * cos(angle)); // Convert to int after calculation
//         y = (int)(radius * sin(angle)); // Convert to int after calculation
//         mlx_put_pixel(map->image, x + (WIDTH / 2), y + (HEIGHT / 2), colour);
//         i++;
//     }
// }