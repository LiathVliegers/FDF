/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:27:47 by livliege          #+#    #+#             */
/*   Updated: 2024/02/20 14:40:55 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liaths_library.h"

char	*itoa_converter(int n, char *str, size_t n_len)
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

char	*ft_itoa(int n, char *str)
{
	size_t	len;
	long	num;

	len = 0;
	num = n;
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	if (n < 0)
	{
		len += 1;
	}
	return (itoa_converter(n, str, len));
}

int	ft_print_number(int d)
{
	char	num[12];
	int		len;

	ft_itoa(d, num);
	len = ft_strlen(num);
	return (write(1, num, len));
}
