/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:05:18 by livliege          #+#    #+#             */
/*   Updated: 2024/02/27 12:07:48 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strnstr() function locates the first occurrence of the null-terminated
	 string little in the string big, where not
     more than len characters are searched.  Characters that appear after a ‘\0’
	 character are not searched.  Since the
     strnstr() function is a FreeBSD specific API, it should only be used when 
	 portability is not a concern.

RETURN VALUES
     If little is an empty string, big is returned; if little occurs nowhere 
	 in big, NULL is returned; otherwise a pointer
     to the first character of the first occurrence of little is returned.

EXAMPLES
     The following sets the pointer ptr to NULL, because only the first 4 
	 characters of largestring are searched:

           const char *largestring = "Foo Bar Baz";
           const char *smallstring = "Bar";
           char *ptr;

           ptr = strnstr(largestring, smallstring, 4);
*/

#include "../../../inc/lib_liath.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (big == NULL && little == NULL)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	j = 0;
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		if (big[i] == little[0])
			j = 1;
		else
			j = 0;
		i++;
	}
	return (NULL);
}
