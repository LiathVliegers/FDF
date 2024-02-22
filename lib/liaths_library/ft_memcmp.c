/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:36:20 by livliege          #+#    #+#             */
/*   Updated: 2024/02/20 14:40:26 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The memcmp() function compares the first n bytes (each interpreted as 
	   unsigned char) of the memory areas s1 and s2.

RETURN VALUE
       The  memcmp()  function  returns  an integer less than, equal to, 
	   or greater than zero if the first n bytes of s1 is
       found, respectively, to be less than, to match, 
	   or be greater than the first n bytes of s2.

       For a nonzero return value, the sign is determined by the 
	   sign of the difference between the  first  pair  of  bytes
       (interpreted as unsigned char) that differ in s1 and s2.

       If n is zero, the return value is zero.
*/

#include "liaths_library.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main()
// {
// 	char str1[] = "hahal";
// 	char str2[] = "hallo";

// 	char str3[] = "cheese";
// 	char str4[] = "Cheese";

// 	char str5[] = "Coding is very hard";
// 	char str6[] = "Coding is very easy";

// 	char str7[] = "neverGoingToGiveYouUp";
// 	char str8[] = "neverGoingToGiveYouDown";

// 	char str9[] = "a";
// 	char str10[] = "ab";

// 	char str11[] = "Have you tried explaining it to the rubber duck?";
// 	char str12[] = "Have you tried explaining it to the rubber duck?";

// 	int arr1[] = {1,2,9,4,5,6,7,8,9};
// 	int arr2[] = {1,2,3,4,5,6,7,8,9};

// 	int arr3[] = {12637,2,3};
// 	int arr4[] = {12657,2,3};

// 	printf("%d\n", ft_memcmp(str1, str2, 5));
// 	printf("%d\n", memcmp(str1, str2, 5));

// 	printf("%d\n", ft_memcmp(str3, str4, 5));
// 	printf("%d\n", memcmp(str3, str4, 5));

// 	printf("%d\n", ft_memcmp(str5, str6, 5));
// 	printf("%d\n", memcmp(str5, str6, 5));

// 	printf("%d\n", ft_memcmp(str7, str8, 5));
// 	printf("%d\n", memcmp(str7, str8, 5));

// 	printf("%d\n", ft_memcmp(str9, str10, 5));
// 	printf("%d\n", memcmp(str9, str10, 5));

// 	printf("%d\n", ft_memcmp(str11, str12, 5));
// 	printf("%d\n", memcmp(str11, str12, 5));

// 	printf("%d\n", ft_memcmp(arr1, arr2, (9 * 4)));
// 	printf("%d\n", memcmp(arr1, arr2, (9 * 4)));

// 	printf("%d\n", ft_memcmp(arr3, arr4, (9 * 4)));
// 	printf("%d\n", memcmp(arr3, arr4, (9 * 4)));

// 	// ft_memcmp(str1, str2, 5)
// 	// memcmp(str1, str2, 5)
// 	// ft_memcmp(arr1, arr2, 9)
// 	// memcmp(arr1, arr2, 9)

// 	return (0);
// }
