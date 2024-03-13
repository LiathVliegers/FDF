/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:46:50 by livliege          #+#    #+#             */
/*   Updated: 2024/03/13 19:20:46 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"


int32_t ft_pixel_colour(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}	


uint32_t convert_colour(char* colour_str)
{
	(void)colour_str;
	// return(255255255);
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
	hex_colour = convert_colour(col);
	free(col);
	free(colour);
	ft_free_matrix(split_line);
	return(hex_colour);
}


// ----------------------- van github :


// uint32_t	color_create(char **points, int i)
// {
// 	int			red;
// 	int			green;
// 	int			blue;
// 	char		*str_color;
// 	uint32_t	color;

// 	str_color = ft_strchr(points[i], ',');
// 	if (str_color)
// 	{
// 		color = ft_atohex(str_color + 3);
// 		red = ((color >> 16) & 0xFF);
// 		green = ((color >> 8) & 0xFF);
// 		blue = (color & 0xFF);
// 		color = rgb_combine(red, green, blue) | 0xFF;
// 		return (color);
// 	}	
// 	else
// 		return (0xFFFFFFFF);
// }


// unsigned int	ft_atohex(const char *hex)
// {
// 	int				i;
// 	unsigned int	nbr;

// 	i = 0;
// 	nbr = 0;
// 	while (hex[i] == ' ' || hex[i] == '\f' || hex[i] == '\n'
// 		|| hex[i] == '\r' || hex[i] == '\t' || hex[i] == '\v')
// 			i++;
// 	while (ft_isalnum(hex[i]) > 0 || hex[i] == '\n')
// 	{
// 		if (hex[i] >= '0' && hex[i] <= '9')
// 			nbr += hex[i] - '0';
// 		else if (hex[i] >= 'a' && hex[i] <= 'z')
// 			nbr += hex[i] - 'W';
// 		else if (hex[i] >= 'A' && hex[i] <= 'Z')
// 			nbr += hex[i] - '7';
// 		if (ft_isalnum(hex[i + 1]) == 1)
// 			nbr *= 16;
// 		i++;
// 	}
// 	return (nbr);
// }

