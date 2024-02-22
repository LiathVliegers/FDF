/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:46:16 by livliege          #+#    #+#             */
/*   Updated: 2024/02/20 14:39:55 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 		ft_itoa
Prototype 			char *ft_itoa(int n);
Turn in files 		-
Parameters 			n: the integer to convert.
Return value 		The string representing the integer.
					NULL if the allocation fails.
External functs. 	malloc
Description 		Allocates (with malloc(3)) and returns a string
					representing the integer received as an argument.
					Negative numbers must be handled.
*/

#include "liaths_library.h"

char	*converter(int n, char *str, size_t n_len)
{
	long	num;

	num = n;
	if (n < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	str[n_len] = '\0';
	n_len -= 1;
	while (num != 0)
	{
		str[n_len] = (num % 10 + '0');
		num /= 10;
		n_len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	n_len;
	long	num;
	char	*str;

	n_len = 0;
	num = n;
	while (num != 0)
	{
		n_len++;
		num /= 10;
	}
	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	if (n < 0)
		n_len += 1;
	str = (char *)malloc(n_len + 1);
	if (str == NULL)
		return (NULL);
	else
		str = converter(n, str, n_len);
	return (str);
}

// int main()
// {
// 	int num = 2147483647;
// 	int num1 = -2147483648;
// 	int num2 = -278278;
// 	int num3 = 278278;
// 	int num4 = 0;

// 	printf("%s\n", ft_itoa(num));
// 	printf("%s\n", ft_itoa(num1));
// 	printf("%s\n", ft_itoa(num2));
// 	printf("%s\n", ft_itoa(num3));
// 	printf("%s\n", ft_itoa(num4));
// }
