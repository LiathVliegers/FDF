/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:13:17 by livliege          #+#    #+#             */
/*   Updated: 2024/06/04 20:46:19 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	fill_canvas(t_map_data *map)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < map->image->height)
	{
		x = 0;
		while (x < map->image->width)
		{
			if (x < map->image->width && y < map->image->height)
				mlx_put_pixel(map->image, x, y, 0x333333FF);
			x++;
		}
		y++;
	}
}

void	print_menu(t_map_data *map)
{
	map->menu_texture = mlx_load_png("./img/FDF.png");
	if (!map->menu_texture)
		ft_exit("Loading the menu failed\n");
	map->menu_image = mlx_texture_to_image(map->window, map->menu_texture);
	if (!map->menu_image)
		ft_exit("Loading the menu failed\n");
	mlx_resize_image(map->menu_image, MENU_WIDTH, HEIGHT);
	if (mlx_image_to_window(map->window, map->menu_image, 0, 0) < 0)
		ft_exit("Loading the menu failed\n");
}

void	create_window(t_map_data *map)
{
	map->window = mlx_init(WIDTH, HEIGHT, map->title, false);
	if (map->window == NULL)
		ft_exit("Malloc allocation failed\n");
	map->image = mlx_new_image(map->window, WIDTH - MENU_WIDTH, HEIGHT);
	if (map->image == NULL)
	{
		mlx_terminate(map->window);
		ft_exit("Malloc allocation failed\n");
	}
	mlx_image_to_window(map->window, map->image, MENU_WIDTH, 0);
	print_menu(map);
	fill_canvas(map);
	draw_fdf(map);
	mlx_loop_hook(map->window, key_is_pressed, map);
	mlx_loop(map->window);
	mlx_delete_image(map->window, map->menu_image);
	mlx_delete_texture(map->menu_texture);
	mlx_terminate(map->window);
}

int	main(int argc, char **argv)
{
	t_map_data	*map;

	if (argc != 2)
		ft_exit("Incorrect number of arguments\n");
	map = (t_map_data *)ft_calloc(sizeof(t_map_data), 1);
	if (map == NULL)
		ft_exit("Malloc allocation failed\n");
	read_map(map, argv[1]);
	create_window(map);
	clear_everything(map);
}
