/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_and_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:54:13 by livliege          #+#    #+#             */
/*   Updated: 2024/06/03 16:03:43 by livliege         ###   ########.fr       */
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

uint32_t	get_colour(char *colour)
{
	char		*col;
	int			r;
	int			g;
	int			b;
	uint32_t	rgba;

	col = ft_strtrim(colour, "\n");
	rgba = atohex(col);
	r = get_r(rgba);
	g = get_g(rgba);
	b = get_b(rgba);
	rgba = ft_pixel_colour(r, g, b, 0xFF);
	free(col);
	return (rgba);
}

float	get_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	get_mod(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}
