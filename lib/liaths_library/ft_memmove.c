/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:36:17 by livliege          #+#    #+#             */
/*   Updated: 2024/02/20 14:40:34 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The  memmove() function copies n bytes from memory area src 
	   to memory area dest.  
       The memory areas may overlap: copying takes place as though the 
	   bytes in src are first copied into a temporary array that does not 
	   overlap src or dest, and the bytes are then  copied  from the temporary 
	   array to dest.
	   
if dest is "bigger" that src:	->		if (dest1 > src1 && dest1 - src1 < n)
		|| to overlaps with from 						||
		||  <from......>         						||
		||         <to........>  						||
		|| copy in reverse, to avoid overwriting from 	||
		
if src is "bigger" that dest:	->  	if (src1 > dest1 && src1 - dest1 < n)
		|| to overlaps with from 						||
		||        <from......>   						||
		||  <to........>         						||
		|| copy forwards, to avoid overwriting from 	||

RETURN VALUE
       The memmove() function returns a pointer to dest.
*/

#include "liaths_library.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;
	size_t			i;

	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	if (dest1 == src1 || n == 0)
		return (dest);
	if (dest1 > src1 && dest1 - src1 < (int)n)
	{
		i = n;
		while (i > 0)
		{
			dest1[i - 1] = src1[i - 1];
			i--;
		}
		return (dest);
	}
	else
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
}

// #include <stdio.h>

// int main()
// {
// 	char src[] = "I love chocolate!";
// 	char dest[50] = "Hellloooooow ";

// 	char src1[] = "I love chocolate!";
// 	char dest1[50] = "Hellloooooow ";

// 	printf("ft_memmove: %s\n", (char *)ft_memmove(dest + 13, src, 18));
// 	printf("memmove: %s\n", (char *)memmove(dest1 + 13, src1, 18));

// 	char src2[] = "I love chocolate!";
// 	char dest2[50] = "Hellloooooow ";

// 	char src3[] = "I love chocolate!";
// 	char dest3[50] = "Hellloooooow ";

// 	ft_memmove(dest2 + 13, src2, 18);
// 	memmove(dest3 + 13, src3, 18);

// 	printf("ft_memmove: %s\n", dest2);
// 	printf("memmove: %s\n", dest3);

// 	int arr1[] = {9,9,9,9,9,9,9,9};
// 	int arr2[] = {1,1,1,1,1,1,1,1};

// 	int arr3[] = {9,9,9,9,9,9,9,9};
// 	int arr4[] = {1,1,1,1,1,1,1,1};

// 	int i = 0;

// 	ft_memmove(arr2, arr1, (4 *sizeof(int)));
//     memmove(arr4, arr3, (4 *sizeof(int)));

// 	printf("ft_memmove: ");
// 	while (i < 8)
//     {
//         printf("%d ", arr2[i]);
//         i++;
//     }
//     printf("\n");
//     i = 0;

// 	printf("memmove: ");
//     while (i < 8)
//     {
//         printf("%d ", arr4[i]);
//         i++;
//     }
//     printf("\n");

// 	return (0);
// }