/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:32:52 by livliege          #+#    #+#             */
/*   Updated: 2024/02/20 14:42:21 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 		ft_strmapi
Prototype 			char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
Turn in files 		-
Parameters 			s: The string on which to iterate.
					f: The function to apply to each character.
Return value 		The string created from the successive applications of ’f’.
					Returns NULL if the allocation fails.
External functs. 	malloc
Description 		Applies the function ’f’ to each character of the
					string ’s’, and passing its index as first argument
					to create a new string (with malloc(3)) resulting
					from successive applications of ’f’.
*/

#include "liaths_library.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
	// ft_striteri
}
