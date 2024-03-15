/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:46:50 by livliege          #+#    #+#             */
/*   Updated: 2024/03/15 18:33:13 by livliege         ###   ########.fr       */
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


// uint32_t convert_colour(char* colour_str)
// {
// 	(void)colour_str;
	
// 	// FF0000
// 	return(0xFFFFFFFF);
// }



//////////////////////////////////////////
// HOW DOES THIS WORK???????????????????????????????? FML
//////////////////////////////////////////



int	atohex(char *hex)
{
	int	i;
	int	numb;

	i = 0;
	numb = 0;

	while (hex[i] != '\0') 
	{
        if (hex[i] >= '0' && hex[i] <= '9')
            numb = numb * 16 + (hex[i] - '0');
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            numb = numb * 16 + (hex[i] - 'a' + 10);
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            numb = numb * 16 + (hex[i] - 'A' + 10);
        i++;
    }
	ft_printf("numb = %d\n", numb);

    return (numb);
}

uint32_t get_colour(char* line)
{
	char		**split_line;
	char		*colour;
	char		*col;
	int			r;
	int			g;
	int			b;
	int			a;
	int			int_colour;
	uint32_t 	rgba;

	split_line = ft_split(line, ',');
	if (split_line == NULL)
		ft_exit(2);	// 2: ERROR: Memory allocation failed
	// colour = ft_substr(split_line[1], 2, 6);
	colour = split_line[1];

	ft_printf("coloursssss = %s\n", colour);

	col = ft_strtrim(colour, "\n");
	int_colour = atohex(col);

	ft_printf("int_colour = %d\n", int_colour);
	
	r = get_r(int_colour);
	g = get_g(int_colour);
	b = get_b(int_colour);
	a = 0xFF;
	rgba = ft_pixel_colour(r, g, b, a);
	free(col);
	// free(colour);
	ft_free_matrix(split_line);
	
	ft_printf("colour = %X\n", rgba);
	
	return(rgba);
	// return(0xFFFFFFFF);
}



