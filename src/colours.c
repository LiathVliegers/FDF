/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:46:50 by livliege          #+#    #+#             */
/*   Updated: 2024/03/19 13:02:55 by livliege         ###   ########.fr       */
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
	ft_printf("numb = %x\n", numb);
    return (numb);
}

uint32_t get_colour(char* line)
{
	char		**split_lines;
	char		*colour;
	char		*col;
	int			r;
	int			g;
	int			b;
	int			a;
	uint32_t 	rgba;

	split_lines = ft_split(line, ',');
	if (split_lines == NULL)
		ft_exit(2);	// 2: ERROR: Memory allocation failed
	colour = split_lines[1];
	col = ft_strtrim(colour, "\n");
	rgba = atohex(col);
	r = get_r(rgba);
	g = get_g(rgba);
	b = get_b(rgba);
	a = 0xFF;
	rgba = ft_pixel_colour(r, g, b, a);
	free(col);
	ft_free_matrix(split_lines);
	return(rgba);
}



