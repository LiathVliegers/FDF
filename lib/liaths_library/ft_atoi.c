/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:50:40 by livliege          #+#    #+#             */
/*   Updated: 2024/02/20 14:39:00 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The  atoi()  function converts the initial portion of the string 
	   pointed to by nptr to int.  The behavior is the same as

           strtol(nptr, NULL, 10);

       except that atoi() does not detect errors.

       The atol() and atoll() functions behave the same as atoi(), 
	   except that they  convert  the  initial  portion  of  the
       string to their return type of long or long long.

RETURN VALUE
       The converted value or 0 on error.
*/

#include "liaths_library.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	numbr;

	sign = 1;
	numbr = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = sign * -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		numbr = numbr * 10 + *nptr - '0';
		nptr++;
	}
	numbr = numbr * sign;
	return (numbr);
}

// #include <stdio.h>

// int main(void)
// {
//         char getal[] = "-9999959869999";

//         printf("%d\n", ft_atoi(getal));
//         printf("%d\n", atoi(getal));
// }
