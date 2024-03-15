/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:46:50 by livliege          #+#    #+#             */
/*   Updated: 2024/03/15 17:13:48 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"


int32_t ft_pixel_colour(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}	

int get_r(int rgba)
{
    return ((rgba >> 24) & 0xFF);
}

// Get the green channel.
int get_g(int rgba)
{
    return ((rgba >> 16) & 0xFF);
}

// Get the blue channel.
int get_b(int rgba)
{
    return ((rgba >> 8) & 0xFF);
}

// Get the alpha channel.
int get_a(int rgba)
{
    return (rgba & 0xFF);
}

uint32_t convert_colour(char* colour_str)
{
	(void)colour_str;
	
	// FF0000
	return(0xFFFFFFFF);
}


uint32_t get_colour(char* line)
{
	char		**split_line;
	char		*colour;
	char		*col;
	uint32_t 	hex_colour;

	split_line = ft_split(line, ',');
	if (split_line == NULL)
		ft_exit(2);	// 2: ERROR: Memory allocation failed
	colour = ft_substr(split_line[1], 2, 6);
	col = ft_strtrim(colour, "\n");
	ft_printf("colour = %s", col);
	hex_colour = convert_colour(col);
	free(col);
	free(colour);
	ft_free_matrix(split_line);
	return(hex_colour);
}



