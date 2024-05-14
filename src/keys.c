/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:55:31 by livliege          #+#    #+#             */
/*   Updated: 2024/05/14 17:45:35 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	key_action(int key, t_map_data* map)
{
	if (key == MLX_KEY_Z)
		map->scale += 0.5;	
	if (key == MLX_KEY_X)
		map->scale -= 0.5;	
	if (key == MLX_KEY_RIGHT)
		map->x_offset += 8;
	if (key == MLX_KEY_LEFT)
		map->x_offset -= 8;	
	if (key == MLX_KEY_UP)
		map->y_offset -= 8;
	if (key == MLX_KEY_DOWN)
		map->y_offset += 8;
	if (key == MLX_KEY_W)
		map->z_scale += 0.05;
	if (key == MLX_KEY_S)
		map->z_scale -= 0.05;
	if (key == MLX_KEY_A)
		map->angle += 0.01;
	if (key == MLX_KEY_D)
		map->angle -= 0.01;
}

void	key_action_two(int key, t_map_data* map)
{
	if (key == MLX_KEY_ESCAPE)
		mlx_close_window(map->window);
	if (key == MLX_KEY_I)
		map->is_isometric = 1;
	if (key == MLX_KEY_O)
		map->is_isometric = 0;
	if (key == MLX_KEY_R)
		set_position(map);
}

int	what_key(t_map_data *map)
{
	int			i;
	const int	keys[] = {MLX_KEY_ESCAPE, MLX_KEY_Z, MLX_KEY_X, \
	MLX_KEY_RIGHT, MLX_KEY_LEFT, MLX_KEY_DOWN, MLX_KEY_UP, \
	MLX_KEY_W, MLX_KEY_S, MLX_KEY_D, MLX_KEY_A, \
	MLX_KEY_I, MLX_KEY_O, MLX_KEY_R, 0};

	i = 0;
	while (keys[i] != 0)
	{
		if (mlx_is_key_down(map->window, keys[i]))
			return (keys[i]);
		i++;
	}
	return (0);
}

void	key_is_pressed(void *data)
{
	t_map_data *map = data;
	int key;
	
	key = what_key(map);
	if (key > 0)
	{
		key_action(key, map);
		key_action_two(key, map);
		mlx_delete_image(map->window, map->image);
		map->image = mlx_new_image(map->window, IMG_WIDTH, HEIGHT);
		mlx_image_to_window(map->window, map->image, MENU_WIDTH, 0);
		draw_FDF(map);
	}
}
