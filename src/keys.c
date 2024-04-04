/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:55:31 by livliege          #+#    #+#             */
/*   Updated: 2024/04/04 18:02:29 by livliege         ###   ########.fr       */
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
		map->z_scale += 0.3;
	if (key == MLX_KEY_S)
		map->z_scale -= 0.3;
	if (key == MLX_KEY_A)
		map->angle += 0.02;
	if (key == MLX_KEY_D)
		map->angle -= 0.02;
		
	// this is buggy, make better or take it out.
	if (key == MLX_KEY_I)
		map->is_isometric = 1;
		
	if (key == MLX_KEY_O)
		map->is_isometric = 0;

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
	keys[11] = MLX_KEY_I;
	keys[12] = MLX_KEY_O;
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
		map->image = mlx_new_image(map->window, WIDTH - 700, HEIGHT);
		mlx_image_to_window(map->window, map->image, 700, 0);
		draw_FDF(map);
	}
}
