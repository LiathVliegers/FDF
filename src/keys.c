/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:55:31 by livliege          #+#    #+#             */
/*   Updated: 2024/03/21 16:43:56 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	key_action(int key, t_map_data* map)
{
	if (key == MLX_KEY_ESCAPE)
		mlx_close_window(map->window);
	if (key == MLX_KEY_Z)
		map->scale += 1.0;	
	if (key == MLX_KEY_X)
		map->scale -= 1.0;	
	if (key == MLX_KEY_RIGHT)
		map->x_offset += 10;
	if (key == MLX_KEY_LEFT)
		map->x_offset -= 10;	
	if (key == MLX_KEY_UP)
		map->y_offset -= 10;
	if (key == MLX_KEY_DOWN)
		map->y_offset += 10;

		
	if (key == MLX_KEY_W)
		map->z_scale += 0.1;
	if (key == MLX_KEY_S)
		map->z_scale -= 0.1;
	if (key == MLX_KEY_A)
		map->angle += 0.1;
	if (key == MLX_KEY_D)
		map->angle -= 0.1;
}


int what_key(t_map_data* map)
{
	int keys[14];
	int i;

	i = 0;
	keys[0] = MLX_KEY_ESCAPE;
	keys[1] = MLX_KEY_Z;
	keys[2] = MLX_KEY_X;
	keys[3] = MLX_KEY_RIGHT;
	keys[4] = MLX_KEY_LEFT;
	keys[5] = MLX_KEY_DOWN;
	keys[6] = MLX_KEY_UP;
	keys[7] = MLX_KEY_W;
	keys[8] = MLX_KEY_S;
	keys[9] = MLX_KEY_A;
	keys[10] = MLX_KEY_D;
	keys[11] = 0;
	keys[12] = 0;
	keys[13] = 0;
	while (keys[i] != 0)
	{
		if (mlx_is_key_down(map->window, keys[i]))
			return(keys[i]); // true
		i++;
	}
	return(0); // false
}

void	key_is_pressed(void *data)
{
	t_map_data *map = data;
	int key;
	
	key = what_key(map);
	if (key > 0)
	{
		key_action(key, map);
		mlx_delete_image(map->window, map->image);
		map->image = mlx_new_image(map->window, WIDTH, HEIGHT);
		mlx_image_to_window(map->window, map->image, 0, 0);
		draw_FDF(map);
	}
}
