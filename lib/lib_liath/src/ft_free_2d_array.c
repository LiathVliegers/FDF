/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:50:30 by livliege          #+#    #+#             */
/*   Updated: 2024/02/27 18:51:48 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/lib_liath.h"

void	*ft_free_2d_array(char **twoD_array)
{
	size_t	i;

	i = 0;
	while (twoD_array[i] != NULL)
	{
		free(twoD_array[i]);
		i++;
	}
	free(twoD_array);
	return (NULL);
}