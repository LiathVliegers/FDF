/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:27:43 by livliege          #+#    #+#             */
/*   Updated: 2024/03/21 16:46:32 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#define MAX(a, b)(a > b ? a : b)
#define MOD(a)(a < 0 ? -a : a)


// -------------------WORKING 3D VERSION:----------------------------------

void bresenham_line(float a_x, float a_y, float b_x, float b_y, t_map_data *map, uint32_t colour) {
    float x_step;
    float y_step;
    float max;

    x_step = b_x - a_x;
    y_step = b_y - a_y;
    max = MAX(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    
    while((int)(a_x - b_x) || (int)(a_y - b_y)) {
        if (a_x >= 0 && a_y >= 0 && a_x < WIDTH && a_y < HEIGHT)
            mlx_put_pixel(map->image, a_x, a_y, colour);
        a_x += x_step;
        a_y += y_step;
    }
}

void draw_FDF(t_map_data *map) {
    int x;
    int y;
    t_point a;
    t_point b;


    y = 0;
    while (y < map->height) {
        x = 0;
        while (x < map->width) {
        // Assigning the values
            a.x = map->points[y][x].x;
            a.y = map->points[y][x].y;
            b.x = map->points[y][x].x;
            b.y = map->points[y][x].y;
        // Height of z value
            a.z = map->points[y][x].z * map->z_scale;
            b.z = map->points[y][x].z * map->z_scale;



// if this is commented out, wtf is happening???????? xD
			float temp_a_x;
			float temp_b_x;
			
			temp_a_x = a.x;
            a.x = ((temp_a_x - a.y) * 1.0) * map->scale;
            a.y = ((temp_a_x + a.y) * 0.5 - a.z) * map->scale;

        	temp_b_x = b.x;
            b.x = ((temp_b_x - b.y) * 1.0) * map->scale;
            b.y = ((temp_b_x + b.y) * 0.5 - b.z) * map->scale;


			// isometric shit, does't really work
			// a.x = (a.x - a.y) * cos(map->angle);
			// a.y = (a.x + a.y) * sin(map->angle) - a.z;
			// b.x = (b.x - b.y) * cos(map->angle);
			// b.y = (b.x + b.y) * sin(map->angle) - b.z;
			
			
            // Add the offset 
            a.x += map->x_offset;
            a.y += map->y_offset;
            b.x += map->x_offset;
            b.y += map->y_offset;
            
            if ((y + 1) < map->height)
                bresenham_line(a.x, a.y, b.x, b.y + map->scale, map, map->points[y][x].colour);
            if (map->points[y][x].last_point == 0)
                bresenham_line(a.x, a.y, b.x + map->scale, b.y, map, map->points[y][x].colour);
            if (map->points[y][x].last_point == 1)
                break;
            x++;
        }
        y++;
    }
}




// -------------------WORKING (FLAT) VERSION:----------------------------------




// void bresenham_line(float a_x, float a_y, float b_x, float b_y, t_map_data *map, uint32_t colour)
// {
// 	float x_step;
// 	float y_step;
// 	float max;

// 	x_step = b_x - a_x;
// 	y_step = b_y - a_y;
// 	max = MAX(MOD(x_step), MOD(y_step));
// 	x_step /= max;
// 	y_step /= max;
	
// 	while((int)(a_x - b_x) || (int)(a_y - b_y))
// 	{
// 		if (a_x >= 0 && a_y >= 0 && a_x < WIDTH && a_y < HEIGHT)
// 			mlx_put_pixel(map->image, a_x, a_y, colour);
// 		a_x += x_step;
// 		a_y += y_step;
// 	}
// }


// void	draw_FDF(t_map_data *map)
// {
// 	int x;
// 	int y;
// 	t_point a;
// 	t_point b;

// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{	
// 		// assigning the values times the scale
// 			a.x = map->points[y][x].x * map->scale;
// 			a.y = map->points[y][x].y * map->scale;
// 			b.x = map->points[y][x].x * map->scale;
// 			b.y = map->points[y][x].y * map->scale;
// 		// height of z value
// 			a.z = map->points[y][x].z * map->z_scale;
// 			b.z = map->points[y][x].z * map->z_scale;
// 		// // making it isometric , DOEST WORK :(
// 		// 	a.x = (a.x - a.y) * cos(map->angle);
// 		// 	a.y = (a.x + a.y) * sin(map->angle) - a.z;
// 		// 	b.x = (b.x - b.y) * cos(map->angle);
// 		// 	b.y = (b.x + b.y) * sin(map->angle) - b.z;
// 		// trying different approach
			
// 		// adding the offset 
// 			a.x += map->x_offset;
// 			a.y += map->y_offset;
// 			b.x += map->x_offset;
// 			b.y += map->y_offset;
			
// 			if ((y + 1) < map->height)
// 				bresenham_line(a.x, a.y, b.x, b.y + map->scale, map, map->points[y][x].colour);
// 			if (map->points[y][x].last_point == 0)
// 				bresenham_line(a.x, a.y, b.x + map->scale, b.y, map, map->points[y][x].colour);
// 			if (map->points[y][x].last_point == 1)
// 				break ;
// 			x++;
// 		}
// 		y++;
// 	}
// }



//----------- OLD VERSION:

// void	draw_FDF(t_map_data *map)
// {
// 	int x;
// 	int y;
// 	// declare point a and point b instead of what i have now

// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{	
// 			ft_printf("a.x = %d\n", map->points[y][x].x);
// 			ft_printf("a.y = %d\n", map->points[y][x].y);
// 			ft_printf("b.x = %d\n", map->points[y][x].x);
// 			ft_printf("b.y = %d\n", map->points[y][x].y);
// 			if ((y + 1) < map->height)
// 				bresenham_line(((map->points[y][x].x  * map->scale) + map->x_offset), ((map->points[y][x].y  * map->scale) + map->y_offset), \
// 				((map->points[y][x].x  * map->scale) + map->x_offset), (((map->points[y][x].y + 1) * map->scale) + map->y_offset), map, map->points[y][x].colour);
// 			if (map->points[y][x].last_point == 0)
// 				bresenham_line(((map->points[y][x].x * map->scale) + map->x_offset), ((map->points[y][x].y  * map->scale) + map->y_offset), \
// 				(((map->points[y][x].x + 1) * map->scale) + map->x_offset), ((map->points[y][x].y * map->scale) + map->y_offset), map, map->points[y][x].colour);
// 			if (map->points[y][x].last_point == 1)
// 				break ;
// 			x++;
// 		}
// 		y++;
// 	}
// }