/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:36:23 by livliege          #+#    #+#             */
/*   Updated: 2024/02/20 14:40:23 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The memchr() function scans the initial n bytes of the memory area 
	   pointed to by s for the first instance
       of c.  Both c and the bytes of the memory area pointed to by s are 
	   interpreted as unsigned char.
RETURN VALUE
       The  memchr() and memrchr() functions return a pointer to the matching 
	   byte or NULL if the character does
       not occur in the given memory area.
*/

#include "liaths_library.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char) c)
		{
			return ((void *)str + i);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h> 
// #include <string.h> 

// int main()
// {
// 	char *str = "Mijn naam is Liath";
// 	char *str1 = "Mijn naam is Liath";

// 	int size = 7;

// 	int arr[] = {2,4,5,6,88,23,95};
// 	int arr1[] = {2,4,5,6,88,23,95};

// 	int	*ptr_arr = arr;
// 	int	*ptr_arr1 = arr1;

// 	int i = 0;

// 	printf("char string: Before (ft_)memchr: %s\n", str);

// 	str = ft_memchr(str, 'L', 15*sizeof(char));
// 	str1 = memchr(str1, 'L', 15*sizeof(char));

//  printf("After ft_memset:  %s\n", str);
// 	printf("After memset:  %s\n", str1);

// 	printf("int array: Before (ft_)memchr: ");
// 	while (i < size)
//     {
//         printf("%d", arr[i]);
//         i++;
//     }
//     printf("\n");

// 	ptr_arr = ft_memchr(arr, 88, 8*sizeof(int));
// 	ptr_arr1 = memchr(arr1, 88, 8*sizeof(int));

// 	printf("After ft_memchr: ");
//     i = 0;
//     while (i < size)
//     {
//         printf("%d ", arr[i]);
//         i++;
//     }
//     printf("\n");

// 	printf("After memchr: ");
//     i = 0;
//     while (i < size)
//     {
//         printf("%d", arr1[i]);
//         i++;
//     }
//     printf("\n");

// 	return (0);
// }
