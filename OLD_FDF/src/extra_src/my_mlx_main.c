/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:50:05 by livliege          #+#    #+#             */
/*   Updated: 2024/03/07 16:57:42 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_liath.h"
#include "../../inc/fdf.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>

#define WIDTH 3000
#define HEIGHT 2000

static mlx_image_t* image;
static mlx_image_t* image1;
static mlx_image_t* image2;
static mlx_image_t* image3;


int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
// image1
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image1->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image1->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image1->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image1->instances[0].x += 5;
// image2
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		image2->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		image2->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		image2->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		image2->instances[0].x += 5;
// image3
	if (mlx_is_key_down(mlx, MLX_KEY_I))
		image3->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_K))
		image3->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_J))
		image3->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_L))
		image3->instances[0].x += 5;
}



static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}



// 
int32_t	main(int argc, char** argv)
{
	// Start mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
        error();

	// Try to load the file
	mlx_texture_t* texture1 = mlx_load_png("/home/livliege/Documents/github/FDF/img/maurers_rose.png");
	mlx_texture_t* texture2 = mlx_load_png("/home/livliege/Documents/github/FDF/img/maurers_rose(1).png");
	mlx_texture_t* texture3 = mlx_load_png("/home/livliege/Documents/github/FDF/img/maurers_rose(2).png");
	if (!texture1 || !texture2 || !texture3)
        error();
	
	// Convert texture to a displayable image
	image = mlx_new_image(mlx, 500, 500);
	image1 = mlx_texture_to_image(mlx, texture1);
	image2 = mlx_texture_to_image(mlx, texture2);
	image3 = mlx_texture_to_image(mlx, texture3);
	mlx_resize_image(image1, 500, 500);
	mlx_resize_image(image2, 500, 500);
	mlx_resize_image(image3, 500, 500);
	
	if (!image || !image1 || !image2|| !image3)
        error();

	
	// Display the image
	if (mlx_image_to_window(mlx, image, 0, 0) < 0 || mlx_image_to_window(mlx, image1, 0, 0) < 0 || mlx_image_to_window(mlx, image2, 0, 0) < 0 || mlx_image_to_window(mlx, image3, 0, 0) < 0)
        error();

	mlx_loop_hook(mlx, ft_randomize, mlx);

	// Keeps checking if we pressed any keys, specifically the up, down, left, right and esc keys.
	mlx_loop_hook(mlx, ft_hook, mlx);

	// Makes sure the window stays open, it will loop forever until we close it.
	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(mlx, image);
	mlx_delete_image(mlx, image1);
	mlx_delete_image(mlx, image2);
	mlx_delete_image(mlx, image3);
	mlx_delete_texture(texture1);
	mlx_delete_texture(texture2);
	mlx_delete_texture(texture3);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}


// // this main displays a pixelated picture that you can moe around
// int32_t main(void)
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
	
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

