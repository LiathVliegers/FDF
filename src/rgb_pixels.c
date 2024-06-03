/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:57:29 by liath             #+#    #+#             */
/*   Updated: 2024/06/03 16:02:36 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int32_t	ft_pixel_colour(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_r(int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

int	get_g(int rgba)
{
	return ((rgba >> 16) & 0xFF);
}

int	get_b(int rgba)
{
	return ((rgba >> 8) & 0xFF);
}

int	get_a(int rgba)
{
	return (rgba & 0xFF);
}
