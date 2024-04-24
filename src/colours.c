/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:54:13 by livliege          #+#    #+#             */
/*   Updated: 2024/04/18 16:45:57 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
	numb = (numb << 8) | 0xFF;
	return (numb);
}
int32_t ft_pixel_colour(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}	

int get_r(int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

int get_g(int rgba)
{
	return ((rgba >> 16) & 0xFF);
}

int get_b(int rgba)
{
	return ((rgba >> 8) & 0xFF);
}

int get_a(int rgba)
{
	return (rgba & 0xFF);
}

uint32_t get_colour(char* colour)
{
	char		*col;
	int			r;
	int			g;
	int			b;
	int			a;
	uint32_t 	rgba;
	col = ft_strtrim(colour, "\n");
	rgba = atohex(col);
	r = get_r(rgba);
	g = get_g(rgba);
	b = get_b(rgba);
	a = 0xFF;
	rgba = ft_pixel_colour(r, g, b, a);
	free(col);
	return(rgba);

}