/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:09:05 by livliege          #+#    #+#             */
/*   Updated: 2024/02/20 14:39:47 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       These  functions  check  whether c, which must have the value of an un‐
       signed char or EOF, falls into a certain character class  according  to
       the  specified  locale.
	   
isascii()
        checks whether c is a 7-bit unsigned char value that  fits  into
        the ASCII character set.
		
RETURN VALUE
       The  values  returned  are  nonzero  if  the character c falls into the
       tested class, and zero if not.
*/

#include "liaths_library.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
